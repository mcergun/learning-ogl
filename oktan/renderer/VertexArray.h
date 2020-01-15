#ifndef _OK_VERTEX_ARRAY_H_
#define _OK_VERTEX_ARRAY_H_

#include <vector>

#include <oktan/Core.h>
#include "Buffers.h"

namespace oktan
{
    class VertexArray
    {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual void AddIndexBuffer(IndexBuffer *ebo) = 0;
        virtual void AddIndexBuffer(uint32_t *data, uint32_t size) = 0;
        virtual void AddVertexBuffer(VertexBuffer *vbo) = 0;
        virtual void AddVertexBuffer(float *data, uint32_t size) = 0;
        bool HasIndexBuffer() const;
        bool HasVertexBuffer() const;
        // TODO: Add missing buffer layout functionality and create AddBufferLayout

        static VertexArray * Create();

        uint32_t m_Id = 0;
    protected:
        VertexBuffer * m_Vbo = nullptr;
        IndexBuffer * m_Ebo = nullptr;
    };
}

#endif