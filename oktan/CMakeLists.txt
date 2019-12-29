cmake_minimum_required(VERSION 3.10)

project(oktan VERSION 0.0.0.1)

# Set unneeded parts off
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
# Add glfw, this will define opengl definitions as well
add_subdirectory(vendor/glfw)
# Add glm for math operations
add_subdirectory(vendor/glm)
# Add platform libraries
add_subdirectory(platform/opengl)

include_directories(
    ".."
    "."
    "./vendor/spdlog/include"
    "./vendor/glfw/include"
    "./vendor/glad/include"
    "./vendor/glm"
)


add_library(oktan-engine Buffers.cpp Logger.cpp)
add_library(glad vendor/glad/src/glad.c)

target_link_libraries(oktan-engine glfw glad oktan-opengl)
