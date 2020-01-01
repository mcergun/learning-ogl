cmake_minimum_required(VERSION 3.10)

include_directories(
    "."
    ".."
    "../.."
    "../vendor/glm/"
    "../vendor/glad/include/"
)

add_library(oktan-drawer
            Buffers.cpp
            Shader.cpp
            Window.cpp
)
