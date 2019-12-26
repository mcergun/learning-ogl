cmake_minimum_required(VERSION 3.10)

# Set unneeded parts off
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
# Add glfw, this will define opengl definitions as well
add_subdirectory(vendor/glfw)

add_subdirectory(platform)

include_directories(
    ".."
    "."
    "./vendor/spdlog/include"
    "./vendor/glfw/include"
    )
    
link_libraries(glfw)

add_library(oktan-engine
            Buffers.cpp
            Logger.cpp)
