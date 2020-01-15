#include <glad/glad.h>

#include "OGLVertexArray.h"

namespace oktan
{
    OGLVertexArray::OGLVertexArray()
    {
        glGenVertexArrays(1, &m_Id);
        OK_LOG_INFO("Created vertex array : {}", m_Id);
        Bind();
    }

    void OGLVertexArray::Bind() const
    {
        OK_LOG_TRACE("Bound vertex array : {}", m_Id);
        glBindVertexArray(m_Id);
    }

    void OGLVertexArray::Unbind() const
    {
        OK_LOG_TRACE("Unbound vertex array : {}", m_Id);
        glBindVertexArray(0);
    }

    void OGLVertexArray::AddIndexBuffer(IndexBuffer *ebo)
    {
        OK_LOG_INFO("Added index buffer to vertex array");
        m_Ebo = ebo;
        m_Ebo->Bind();
    }
    
    void OGLVertexArray::AddIndexBuffer(uint32_t *data, uint32_t size)
    {
        OK_LOG_INFO("Created index buffer for vertex array");
        m_Ebo = IndexBuffer::Create(data, size);
        m_Ebo->Bind();
    }
    
    void OGLVertexArray::AddVertexBuffer(VertexBuffer *vbo)
    {
        OK_LOG_INFO("Added vertex buffer to vertex array");
        m_Vbo = vbo;
        m_Vbo->Bind();
    }
    
    void OGLVertexArray::AddVertexBuffer(float *data, uint32_t size)
    {
        OK_LOG_INFO("Created vertex buffer for vertex array");
        m_Vbo = VertexBuffer::Create(data, size);
        m_Vbo->Bind();
    }
    
}