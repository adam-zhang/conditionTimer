/********************************************************************************
> FileName:	Timer.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Mar 23 15:57:21 2023
********************************************************************************/

#include "Timer.h"
#include "HandleGenerator.h"
#include "Subtimer.h"
#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

Timer::Timer()
{
	run();
}

Timer::~Timer()
{
	cancelAllTimers();
	shouldExit_ = true;
	thread_.join();
}

int Timer::setTimer(int interval, std::function<void()> func)
{
	auto p = make_shared<Subtimer>(interval, func);
	auto handle = HandleGenerator::instance().getHandle();
	map_.emplace(handle, p);
	return handle;
}

void Timer::cancelTimer(int handle)
{
	std::lock_guard<mutex> lock(mutex_);
	if (map_.find(handle) == map_.end())
	{
		cout << "handle:" << handle << endl;
		return;
	}
	map_.erase(handle);
	HandleGenerator::instance().removeHandle(handle);
	cout << "after cancel timer\n";
}

void Timer::cancelAllTimers()
{
	std::lock_guard<mutex> lock(mutex_);
	map_.clear();
	HandleGenerator::instance().removeAll();
}

void Timer::run()
{
	thread_ = std::thread(&Timer::threadFunc, this);
}

void Timer::threadFunc()
{
	while(!shouldExit_)
	{
		std::unique_lock<mutex> lock(waitingMutex_);
		if (condition_.wait_for(lock, 300us) == cv_status::timeout)
		{
			if (map_.empty())
				return;
			runTasks();
		}
	}
}

void Timer::runTasks()
{
	cout << "entering " << __func__ << endl;
	std::lock_guard<mutex> lock(mutex_);
	for(auto pair : map_)
	{
		if (pair.second->expired())
		{
			pair.second->task()();
			pair.second->addCount();
		}
	}
}
