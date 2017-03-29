cmake_minimum_required(VERSION 3.6)
project(Lab_3_4)

set(CMAKE_CXX_STANDARD 11)

set(msse3)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

#for SIMD -msse -msse2
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse3")

#openMP_parallel_multiplication.cpp
#sequential_multiplication.cpp
#simd_matrix_multiplication.cpp


set(SOURCE_FILES simd_matrix_multiplication.cpp support_functions.h)
add_executable(Lab_3_4 ${SOURCE_FILES})