cmake_minimum_required(VERSION 3.19)
project(i8080 C)

set(CMAKE_C_STANDARD 99)

add_executable(i8080 "src/Main - i8080.c" "src/Main - i8080.h" src/Utils.c src/Utils.h)