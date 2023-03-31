/********************************************************************************
> FileName:	Subtimer.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Mar 23 15:46:39 2023
********************************************************************************/

#include "Subtimer.h"
#include <iostream>

using namespace std;
using namespace std::chrono;

Subtimer::Subtimer(int inteval, function<void()> task)
	: interval_(inteval)
	  , task_(task)
	  , origin_(system_clock::now())

{}



bool Subtimer::expired()
{
	auto current = system_clock::now();
	auto triggerTime = origin_ + duration<uint64_t, std::ratio<1, 1000>>(count_ * interval_);
	return triggerTime < current;
}


//uint64_t Subtimer::origin()
//{ 
//	return duration_cast<std::chrono::milliseconds>(origin_.time_since_epoch()).count();
//}
