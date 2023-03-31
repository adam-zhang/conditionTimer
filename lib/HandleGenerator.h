/********************************************************************************
> FileName:	HandleGenerator.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Mar 23 16:01:34 2023
********************************************************************************/
#ifndef HANDLEGENERATOR_H
#define HANDLEGENERATOR_H

#include <vector>

class HandleGenerator
{
public:
	HandleGenerator();
	~HandleGenerator();
public:
	static HandleGenerator& instance();
private:
	static HandleGenerator* instance_;

public:
	int getHandle();
	void removeHandle(int handle);
	void removeAll();
private:
	std::vector<int> handles_;
};
#endif//HANDLEGENERATOR_H
