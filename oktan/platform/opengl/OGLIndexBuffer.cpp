#include <glad/glad.h>
#include "platform/opengl/OGLIndexBuffer.h"

OGLIndexBuffer::OGLIndexBuffer(float *indices, uint32_t size)
{
    glGenBuffers(1, &m_Id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void OGLIndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
}

void OGLIndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}