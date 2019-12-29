cmake_minimum_required(VERSION 3.10)

project(oktan-app VERSION 0.0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

configure_file(oktan/Version.cfg oktan/Version.h)

add_subdirectory(oktan)

include_directories(
    ".."
    "."
    "./oktan"
    "./oktan/vendor/glad/include"
)

add_executable(oktan-app oktan/platform/opengl/main.cpp)


target_link_libraries(oktan-app oktan-engine)