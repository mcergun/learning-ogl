cmake_minimum_required(VERSION 3.11)

include_directories(
    ".."
    "../.."
    "../../.."
    "../../vendor/glad/include"
    "../../vendor/glfw/include"
)

add_library(oktan-glfw STATIC GlfwWindow.cpp GlfwInputHandler.cpp)

target_link_libraries(oktan-glfw glfw)
