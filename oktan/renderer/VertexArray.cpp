#include "VertexArray.h"
#include <oktan/platform/opengl/OGLVertexArray.h>

namespace oktan
{
    VertexArray * VertexArray::Create()
    {
#if OK_OGL_ENABLED == 1
        return new OGLVertexArray();
#else
        return nullptr;
#endif
    }

    bool VertexArray::HasIndexBuffer() const
    {
        return m_Ebo != nullptr;
    }

    bool VertexArray::HasVertexBuffer() const
    {
        return m_Vbo != nullptr;
    }
}