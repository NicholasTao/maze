cmake_minimum_required(VERSION 3.20)
project(try)

set(CMAKE_CXX_STANDARD 14)

add_executable(try main.cpp model/Grid.cpp model/Grid.h model/constant.h model/location.h)
