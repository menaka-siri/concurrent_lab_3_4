cmake_minimum_required(VERSION 3.6)
project(Lab_3_4)

set(CMAKE_CXX_STANDARD 11)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

#openMP_parallel_multiplication.cpp
#sequential_multiplication.cpp

set(SOURCE_FILES openMP_parallel_multiplication.cpp support_functions.h)
add_executable(Lab_3_4 ${SOURCE_FILES})