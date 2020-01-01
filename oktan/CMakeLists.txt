cmake_minimum_required(VERSION 3.10)

project(oktan VERSION 0.0.0.1)

# Set unneeded parts off
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add vendor libraries
add_subdirectory(vendor)
# add_subdirectory(vendor/glad)
# add_subdirectory(vendor/glfw)
# add_subdirectory(vendor/glm)

# Add platform libraries
add_subdirectory(platform)
# add_subdirectory(platform/opengl)
# add_subdirectory(platform/glfw)

# Add engine parts
add_subdirectory(drawer)

# Add include paths
include_directories(
    ".."
    "."
    "./vendor/spdlog/include"
    "./vendor/glfw/include"
    "./vendor/glad/include"
    "./vendor/glm"
)

add_library(oktan-generic
    Logger.cpp
    FileLoader.cpp
)

add_library(oktan-engine INTERFACE)

target_link_libraries(oktan-engine INTERFACE
oktan-drawer
oktan-opengl
oktan-glfw
oktan-vendor
oktan-generic
)
