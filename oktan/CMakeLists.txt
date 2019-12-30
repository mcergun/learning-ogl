cmake_minimum_required(VERSION 3.10)

project(oktan VERSION 0.0.0.1)

# Set unneeded parts off
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add vendor libraries
add_subdirectory(vendor)

# Add platform libraries
add_subdirectory(platform)

# Add include paths
include_directories(
    ".."
    "."
    "./vendor/spdlog/include"
    "./vendor/glfw/include"
    "./vendor/glad/include"
    "./vendor/glm"
)


add_library(oktan-engine Buffers.cpp Logger.cpp Window.cpp)

# Link vendors
target_link_libraries(oktan-engine oktan-vendor)
# Link platforms
target_link_libraries(oktan-engine oktan-platform)
