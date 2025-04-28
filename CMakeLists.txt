cmake_minimum_required(VERSION 3.29)
project(elaboratoTimer)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_SOURCES
        Date.cpp
        Time.cpp
        Timer.cpp
)

add_library(core ${PROJECT_SOURCES})

target_include_directories(core PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(elaboratoTimer main.cpp)

add_subdirectory(test)
