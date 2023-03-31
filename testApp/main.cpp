#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"

using namespace std;
using namespace chrono;

ostream& operator<<(ostream& stream, const chrono::time_point<system_clock>& point)
{
	auto millis = time_point_cast<milliseconds>(point);
	//auto period = point.time_since_epoch();
	stream << millis ;
	return stream;
}

void task1()
{
	cout << "this is task1, now the time is " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() << endl;
}
void task2()
{
	cout << "this is task2, now the time is " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() << endl;
}

void task3()
{
	cout << "this is task3, now the time is " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() << endl;
}

void testTimer()
{
	Timer timer;
	cout << "create two timers and let them run";
	auto handle1 = timer.setTimer(1, task1);
	this_thread::sleep_for(milliseconds(1000));
	auto handle2 = timer.setTimer(2, task2);
	this_thread::sleep_for(milliseconds(1000));
	cout << "add third timer to " << endl;
	auto handle3 = timer.setTimer(4, task3);
	this_thread::sleep_for(milliseconds(1000));
	cout << "remove first timer" << endl;
	timer.cancelTimer(handle1);
	this_thread::sleep_for(milliseconds(1000));
	cout << "remove second timer" << endl;
	timer.cancelTimer(handle2);
	this_thread::sleep_for(milliseconds(1000));
	cout << "remove third timer" << endl;
	timer.cancelTimer(handle3);
	//this_thread::sleep_for(milliseconds(1000));
}

//void testSubtimer()
//{
//	Subtimer timer(1000, task1);
//	cout << timer.expired() << endl;
//	this_thread::sleep_for(1000ms);
//	cout << timer.expired() << endl;
//}

int main(int /*argc*/, char** /*argv*/)
{
	while(true)
	{
		testTimer();
		this_thread::sleep_for(10s);
	}
	return 0;
}
