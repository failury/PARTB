cmake_minimum_required(VERSION 3.13)
project(partB)

set(CMAKE_CXX_STANDARD 14)
set(GPP_ENABLE_WARNINGS "-O0 -Wall -Werror -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP_ENABLE_WARNINGS}")
add_executable(partB main.cpp)