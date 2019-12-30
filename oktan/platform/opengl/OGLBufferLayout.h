#ifndef _OK_OGL_BUFFERLAYOUT_H_
#define _OK_OGL_BUFFERLAYOUT_H_

#include <initializer_list>
#include <vector>
#include <oktan/Core.h>

namespace oktan
{
    struct BufferElement
    {
        BufferElement(BaseType type, uint32_t count, bool normalized) :
            Type(type), Count(count), Offset(0), Normalized(normalized)
        {
        }
        BaseType Type;
        uint32_t Count;
        uint32_t Offset;
        bool Normalized;
    };

    inline static uint32_t BaseTypeToSize(const BaseType type)
    {
        switch (type)
        {
        default:
        case BaseType::Float:
            return 4;
        case BaseType::Float2:
            return 2 * 4;
        case BaseType::Float3:
            return 3 * 4;
        case BaseType::Int:
        case BaseType::UInt:
            return 4;
        case BaseType::Int2:
        case BaseType::UInt2:
            return 2 * 4;
        case BaseType::Int3:
        case BaseType::UInt3:
            return 3 * 4;
        case BaseType::Mat2:
            return 4 * 4;
        case BaseType::Mat3:
            return 9 * 4;
        case BaseType::Mat4:
            return 16 * 4;
        case BaseType::Vec2:
            return 2 * 4;
        case BaseType::Vec3:
            return 3 * 4;
        case BaseType::Vec4:
            return 4 * 4;
        }
    }

    class OGLBufferLayout
    {
    public:
        OGLBufferLayout(const std::initializer_list<BufferElement> &elements);
    public:
        std::vector<BufferElement> m_Elements;
        uint32_t m_Stride = 0;
    };
}

#endif