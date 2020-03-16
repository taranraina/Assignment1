cmake_minimum_required(VERSION 3.15)
project(Player)

set(CMAKE_CXX_STANDARD 14)

add_executable(Player Player.cpp Player.h Test.h Test.cpp playerDriver.cpp)