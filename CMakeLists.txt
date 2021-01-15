cmake_minimum_required(VERSION 3.17)
project(hy352_project)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(hy352_project
        JSONlang.h
        main.cpp)
