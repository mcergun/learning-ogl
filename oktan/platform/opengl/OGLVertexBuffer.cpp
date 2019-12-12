#include <glad/glad.h>
#include "platform/opengl/OGLVertexBuffer.h"

OGLVertexBuffer::OGLVertexBuffer(float *vertices, uint32_t size)
{
    glGenBuffers(1, &m_Id);
    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void OGLVertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void OGLVertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}