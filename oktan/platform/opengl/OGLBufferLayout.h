#ifndef _OK_OGL_BUFFERLAYOUT_H_
#define _OK_OGL_BUFFERLAYOUT_H_

#include <oktan/Core.h>
#include <oktan/renderer/Buffers.h>

namespace oktan
{
    class OGLBufferLayout : public BufferLayout
    {
    public:
        OGLBufferLayout(const std::initializer_list<BufferElement> &list);
    };
}

#endif