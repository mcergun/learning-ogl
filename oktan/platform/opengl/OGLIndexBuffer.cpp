#include <glad/glad.h>
#include "OGLIndexBuffer.h"

namespace oktan
{
    OGLIndexBuffer::OGLIndexBuffer(uint32_t *indices, uint32_t size)
    {
        glGenBuffers(1, &m_Id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        m_Type = BufferType::IndexBuffer;
    }

    OGLIndexBuffer::~OGLIndexBuffer()
    {
        Unbind();
        glDeleteBuffers(1, &m_Id);
    }

    void OGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
    }

    void OGLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}