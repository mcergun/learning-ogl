cmake_minimum_required(VERSION 3.11)

include_directories(
    ".."
    "../.."
    "../../.."
    "../../vendor/glad/include"
    "../../vendor/glm/"
)

add_library(oktan-opengl
            OGLBufferLayout.cpp
            OGLIndexBuffer.cpp
            OGLVertexBuffer.cpp
            OGLShader.cpp
)

# target_link_libraries(oktan-opengl)
