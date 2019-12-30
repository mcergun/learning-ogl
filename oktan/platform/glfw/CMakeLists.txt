cmake_minimum_required(VERSION 3.10)

include_directories(
    ".."
    "../.."
    "../../.."
    "../../vendor/glad/include"
)

add_library(oktan-glfw GlfwWindow.cpp)

target_link_libraries(oktan-glfw glfw)
