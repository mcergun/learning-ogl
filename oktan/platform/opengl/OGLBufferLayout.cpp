#include "OGLBufferLayout.h"

namespace oktan
{
    OGLBufferLayout::OGLBufferLayout(const std::initializer_list<BufferElement> &elements) :
        m_Elements(elements)
    {
        uint32_t totalSize = 0;
        for (auto &e : m_Elements)
        {
            e.Offset = totalSize;
            totalSize += BaseTypeToSize(e.Type) * e.Count;
        }
        m_Stride = totalSize;
    }
}