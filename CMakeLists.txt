cmake_minimum_required(VERSION 3.28)
project(A1)

set(CMAKE_CXX_STANDARD 17)

add_executable(A1 main.cpp
        Point.cpp
        Point.h
        MyArray.cpp
        MyArray.h
        Triangle.cpp
        Triangle.h
        Part1Driver.cpp
        Part2Driver.cpp)
