cmake_minimum_required(VERSION 3.6)
project(Lab_3_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sequential_multiplication.cpp support_functions.h)
add_executable(Lab_3_4 ${SOURCE_FILES})