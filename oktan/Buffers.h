#ifndef _OK_BUFFERS_H_
#define _OK_BUFFERS_H_

#include "Core.h"

namespace oktan
{
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static VertexBuffer * Create(float *data, uint32_t size);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static IndexBuffer * Create(uint32_t *data, uint32_t size);
    };
}

#endif