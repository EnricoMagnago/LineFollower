cmake_minimum_required(VERSION 3.3)
project(LineFollower)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES main.cpp main.cpp)
add_executable(LineFollower ${SOURCE_FILES})