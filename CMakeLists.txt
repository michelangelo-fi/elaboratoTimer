cmake_minimum_required(VERSION 3.29)
project(elaboratoTimer)

set(CMAKE_CXX_STANDARD 17)

add_executable(elaboratoTimer main.cpp
        Date.cpp
        Date.h
        Time.cpp
        Time.h)
