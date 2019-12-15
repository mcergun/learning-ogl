#ifndef _OK_OGL_INDEXBUFFER_H_
#define _OK_OGL_INDEXBUFFER_H_

#include "Core.h"

class OGLIndexBuffer
{
public:
    OGLIndexBuffer(float *indices, uint32_t size);
    ~OGLIndexBuffer();

    virtual void Bind() const;
    virtual void Unbind() const;

private:
    uint32_t m_Id = 0;
};

#endif
