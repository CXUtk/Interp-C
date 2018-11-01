cmake_minimum_required(VERSION 3.10)
project(Interp_C)

set(CMAKE_CXX_STANDARD 11)

add_executable(Interp_C main.cpp Interpreter.cpp Interpreter.h VM/ISA.h Token.h Token.cpp)