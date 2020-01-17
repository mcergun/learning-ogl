#include <glad/glad.h>

#include "OGLBufferLayout.h"

namespace oktan
{
    static inline GLenum BaseTypeToOGLType(BaseType t)
    {
        switch (t)
        {
        case BaseType::Byte:
            return GL_BYTE;
        case BaseType::UByte:
            return GL_UNSIGNED_BYTE;
        case BaseType::Short:
            return GL_SHORT;
        case BaseType::UShort:
            return GL_UNSIGNED_SHORT;
        case oktan::BaseType::Float:
            return GL_FLOAT;
        case oktan::BaseType::Int:
            return GL_INT;
        case oktan::BaseType::UInt:
            return GL_UNSIGNED_INT;
        default:
            return GL_INVALID_ENUM;
        }
    }

    OGLBufferLayout::OGLBufferLayout(const std::initializer_list<BufferElement> &list) :
        BufferLayout(list)
    {
        m_Elements = std::vector<BufferElement>(list);
        uint32_t totalSize = 0;
        for (auto &e : m_Elements)
        {
            e.Offset = totalSize;
            totalSize += (BufferElement::ToSize(e.Type) * e.Count);
        }
        m_Stride = totalSize;
        for (uint32_t i = 0; i < m_Elements.size(); i++)
        {
            BufferElement& e = m_Elements[i];
            glVertexAttribPointer(i, e.Count, BaseTypeToOGLType(e.Type), GL_FALSE, m_Stride, reinterpret_cast<void *>(e.Offset));
            glEnableVertexAttribArray(i);
        }
        OK_LOG_TRACE("Created a buffer layout of {} attributes", list.size());
    }
}