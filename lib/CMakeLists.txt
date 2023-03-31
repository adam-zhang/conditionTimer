cmake_minimum_required(VERSION 3.5)
project(single_thread_timer)
add_definitions(-Wall)
set(CMAKE_CXX_STANDARD 14)
set(sources 
	HandleGenerator.cpp
	Timer.cpp
	Subtimer.cpp
	)
add_library(${PROJECT_NAME} SHARED ${sources})
