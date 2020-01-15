cmake_minimum_required(VERSION 3.11)

include_directories(
    ".."
    "../.."
    "../../.."
    "../../vendor/glad/include"
    "../../vendor/glm"
    "../../vendor/stb"
)

add_library(oktan-opengl STATIC
            OGLBufferLayout.cpp
            OGLIndexBuffer.cpp
            OGLVertexBuffer.cpp
            OGLShader.cpp
            OGLTexture.cpp
            OGLVertexArray.cpp
)

# target_link_libraries(oktan-opengl)
