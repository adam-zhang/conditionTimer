/********************************************************************************
> FileName:	HandleGenerator.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Mar 23 16:01:34 2023
********************************************************************************/

#include "HandleGenerator.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

HandleGenerator::HandleGenerator()
{
	srand(time(nullptr));
}

HandleGenerator::~HandleGenerator()
{
}

HandleGenerator& HandleGenerator::instance()
{
	if (!instance_)
		instance_ = new HandleGenerator;
	return *instance_;
}

HandleGenerator* HandleGenerator::instance_ = nullptr;

void HandleGenerator::removeHandle(int handle)
{
	auto pos = find(handles_.begin(), handles_.end(), handle);
	if (pos != handles_.end())
		handles_.erase(pos);
}

int produceHandle()
{
	return rand();
}

int HandleGenerator::getHandle()
{
	do
	{
		int handle = produceHandle();
		if (find(handles_.begin(), handles_.end(), handle) == handles_.end())
		{
			handles_.emplace_back(handle);
			return handle;
		}
	}while(true);
}

void HandleGenerator::removeAll()
{
	handles_.clear();
}
