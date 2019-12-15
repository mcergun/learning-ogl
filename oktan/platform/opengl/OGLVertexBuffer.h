#ifndef _OK_OGL_VERTEXBUFFER_H_
#define _OK_OGL_VERTEXBUFFER_H_

#include "Core.h"

class OGLVertexBuffer
{
public:
    OGLVertexBuffer(float *vertices, uint32_t size);
    ~OGLVertexBuffer();

    virtual void Bind() const;
    virtual void Unbind() const;

private:
    uint32_t m_Id = 0;
};

#endif