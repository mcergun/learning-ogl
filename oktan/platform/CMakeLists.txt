cmake_minimum_required(VERSION 3.11)

add_subdirectory(opengl)
add_subdirectory(glfw)

add_library(oktan-platform INTERFACE)

target_link_libraries(oktan-platform INTERFACE oktan-opengl oktan-glfw)
