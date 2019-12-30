cmake_minimum_required(VERSION 3.10)

include_directories(
    ".."
    "../.."
    "../../.."
    "../../vendor/glad/include"
)

add_library(oktan-opengl
            OGLBufferLayout.cpp
            OGLIndexBuffer.cpp
            OGLVertexBuffer.cpp
)

target_link_libraries(oktan-opengl glad)
