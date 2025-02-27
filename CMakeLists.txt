cmake_minimum_required(VERSION 3.29)
project(TestDoctest)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp calculator_functions.cpp)

add_executable(tests calculator_functions.cpp test.cpp)