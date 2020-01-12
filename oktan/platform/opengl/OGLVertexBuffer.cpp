#include <glad/glad.h>
#include "OGLVertexBuffer.h"

namespace oktan
{
    OGLVertexBuffer::OGLVertexBuffer(float *vertices, uint32_t size)
    {
        glGenBuffers(1, &m_Id);
        glBindBuffer(GL_ARRAY_BUFFER, m_Id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        OK_LOG_TRACE("created vertex buffer {}", m_Id);
        m_Type = BufferType::VertexBuffer;
    }

    OGLVertexBuffer::~OGLVertexBuffer()
    {
        Unbind();
        glDeleteBuffers(1, &m_Id);
        OK_LOG_TRACE("deleting vertex buffer {}", m_Id);
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
