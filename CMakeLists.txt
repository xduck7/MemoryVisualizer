cmake_minimum_required(VERSION 3.27)
project(MemoryVisualizer)

set(CMAKE_CXX_STANDARD 17)
add_executable(
        MemoryVisualizer main.cpp
        DirectoryReader.cpp
        DirectoryReader.h
        SizeReader.cpp
        SizeReader.h
        Checker.cpp
        Checker.h)
