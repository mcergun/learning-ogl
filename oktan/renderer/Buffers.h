#ifndef _OK_BUFFERS_H_
#define _OK_BUFFERS_H_

#include <oktan/Core.h>

namespace oktan
{
    class Buffer
    {
    public:
        virtual ~Buffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
    
    protected:
        BufferType m_Type;
    };

    class VertexBuffer : public Buffer
    {
    public:
        static VertexBuffer * Create(float *data, uint32_t size);
    };

    class IndexBuffer : public Buffer
    {
    public:
        static IndexBuffer * Create(uint32_t *data, uint32_t size);
    };
}

#endif