/********************************************************************************
> FileName:	Timer.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Mar 23 15:57:21 2023
********************************************************************************/
#ifndef TIMER_H
#define TIMER_H

#include <functional>
#include <map>
#include <memory>
#include <vector>
#include <chrono>
#include <mutex>
#include <thread>
#include <condition_variable>

class Subtimer;

class Timer
{
public:
	Timer();
	~Timer();

public:
	int setTimer(int interval, std::function<void()> task);
	void cancelTimer(int);
	void cancelAllTimers();
private:
	std::map<int, std::shared_ptr<Subtimer>> map_;
	std::condition_variable condition_;
	std::mutex mutex_;
	std::mutex waitingMutex_;
	std::thread thread_;
	bool shouldExit_;
private:
	void run();
	void threadFunc();
	void runTasks();
};
#endif//TIMER_H
