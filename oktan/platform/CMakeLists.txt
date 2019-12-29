cmake_minimum_required(VERSION 3.10)
project(oktan-platform)
add_subdirectory(opengl)
target_link_libraries(oktan-platform opengl)
