/********************************************************************************
> FileName:	Subtimer.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Mar 23 15:46:39 2023
********************************************************************************/

#ifndef SUBTIMER_H
#define SUBTIMER_H

#include <functional>
#include <chrono>

class Subtimer
{
public:
	Subtimer(int interval, std::function<void()> task);

	~Subtimer()
	{
	}


private:
	int interval_;
	std::function<void()> task_;
	std::chrono::time_point<std::chrono::system_clock> origin_;
	int count_ = 1;
public:
	int interval()
	{ return interval_; }
	std::function<void()> task()
	{ return task_; }
	int addCount()
	{ return ++count_; }
	bool expired();

	//uint64_t origin();

};
#endif
