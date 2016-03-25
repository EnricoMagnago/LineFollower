cmake_minimum_required(VERSION 3.3)
project(LineFollower)

find_package(OpenCV REQUIRED)

set(THREAD -pthread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra ${THREAD}")

set(SOURCE_FILES main.cpp Pixel.cpp Pixel.h Common.h)
add_executable(LineFollower ${SOURCE_FILES})

target_link_libraries(LineFollower ${OpenCV_LIBS})