cmake_minimum_required(VERSION 3.10)

project(oktan VERSION 0.0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

configure_file(oktan/Version.cfg oktan/Version.h)

add_executable(oktan oktan/main.cpp)