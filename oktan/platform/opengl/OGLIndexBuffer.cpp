#include <glad/glad.h>
#include "platform/opengl/OGLIndexBuffer.h"

namespace oktan
{
    OGLIndexBuffer::OGLIndexBuffer(uint32_t *indices, uint32_t size)
    {
        glGenBuffers(1, &m_Id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
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