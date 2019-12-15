#ifndef _OK_OGL_INDEXBUFFER_H_
#define _OK_OGL_INDEXBUFFER_H_

#include "Core.h"
#include "Buffers.h"

namespace oktan
{
    class OGLIndexBuffer : public IndexBuffer
    {
    public:
        OGLIndexBuffer(uint32_t *indices, uint32_t size);
        virtual ~OGLIndexBuffer();

        virtual void Bind() const;
        virtual void Unbind() const;

    private:
        uint32_t m_Id = 0;
    };
}

#endif
