cmake_minimum_required(VERSION 3.24)
project(oving6)

set(CMAKE_CXX_STANDARD 17)

add_executable(chess chess.cpp)

add_executable(echo_server echo_server.cpp)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(echo_server ${Boost_LIBRARIES})