cmake_minimum_required(VERSION 3.10)

include_directories(
    "."
    ".."
    "../.."
    "../vendor/glm"
    "../vendor/glad/include"
    "../vendor/stb"
)

add_library(oktan-renderer STATIC
            Buffers.cpp
            Shader.cpp
            Window.cpp
            Texture.cpp
            VertexArray.cpp
)
