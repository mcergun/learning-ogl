#include <glad/glad.h>
#include "platform/opengl/OGLVertexBuffer.h"
#include "Logger.h"

namespace oktan
{
    OGLVertexBuffer::OGLVertexBuffer(float *vertices, uint32_t size)
    {
        Logger::Print("created vertex buffer\n");
        glGenBuffers(1, &m_Id);
        glBindBuffer(GL_ARRAY_BUFFER, m_Id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OGLVertexBuffer::~OGLVertexBuffer()
    {
        Unbind();
        glDeleteBuffers(1, &m_Id);
    }

    void OGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_Id);
    }

    void OGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
} // namespace oktan
