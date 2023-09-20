cmake_minimum_required(VERSION 3.24)
project(oving7)

set(CMAKE_CXX_STANDARD 17)

add_executable(fraction fraction/main.cpp fraction/fraction.cpp)

add_executable(set set/set.cpp set/main_set.cpp)
