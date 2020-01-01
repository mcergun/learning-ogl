#ifndef _OK_OGL_VERTEXBUFFER_H_
#define _OK_OGL_VERTEXBUFFER_H_

#include <Core.h>
#include <oktan/drawer/Buffers.h>

namespace oktan
{
    class OGLVertexBuffer : public VertexBuffer
    {
    public:
        OGLVertexBuffer(float *vertices, uint32_t size);
        virtual ~OGLVertexBuffer();

        virtual void Bind() const;
        virtual void Unbind() const;

    private:
        uint32_t m_Id = 0;
    };
}

#endif