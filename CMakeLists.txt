cmake_minimum_required(VERSION 3.29)
project(elaboratoTimer)

set(CMAKE_CXX_STANDARD 17)

add_executable(elaboratoTimer main.cpp
        Date.cpp
        Date.h
        Time.cpp
        Time.h
        Timer.cpp
        Timer.h)

add_subdirectory(test)
set(SOURCE_FILES
        Date.cpp
        Date.h
        Time.cpp
        Time.h
        Timer.cpp
        Timer.h)
add_executable(my_executable main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(my_executable core)