cmake_minimum_required(VERSION 3.11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)

add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_library(oktan-vendor INTERFACE)
target_link_libraries(oktan-vendor INTERFACE glad glfw glm)
