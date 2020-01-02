#include "Buffers.h"
#include <oktan/platform/opengl/OGLVertexBuffer.h>
#include <oktan/platform/opengl/OGLIndexBuffer.h>

namespace oktan
{
    VertexBuffer * VertexBuffer::Create(float * data, uint32_t size)
    {
        #if OK_OGL_ENABLED == 1
        return new OGLVertexBuffer(data, size);
        #else
        return nullptr;
        #endif
    }

    IndexBuffer * IndexBuffer::Create(uint32_t * data, uint32_t size)
    {
        #if OK_OGL_ENABLED == 1
        return new OGLIndexBuffer(data, size);
        #else
        return nullptr;
        #endif
    }
}