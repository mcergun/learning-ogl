#ifndef _OK_BUFFERS_H_
#define _OK_BUFFERS_H_

#include <initializer_list>

#include <oktan/Core.h>

namespace oktan
{
    struct BufferElement
    {
        BufferElement(BaseType type, uint32_t count, bool normalized) :
            Type(type), Count(count), Offset(0), Normalized(normalized)
        {
        }

        inline static uint32_t ToSize(const BaseType type)
        {
            switch (type)
            {
            case BaseType::Byte:
            case BaseType::UByte:
                return 1;
            case BaseType::Short:
            case BaseType::UShort:
                return 2;
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
            default:
                return 4;
            }
        }

        BaseType Type;
        uint32_t Count;
        uint32_t Offset;
        bool Normalized;
    };

    class Buffer
    {
    public:
        virtual ~Buffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
    
    protected:
        BufferType m_Type;
    };

    class VertexBuffer : public Buffer
    {
    public:
        static VertexBuffer * Create(float *data, uint32_t size);
    };

    class IndexBuffer : public Buffer
    {
    public:
        static IndexBuffer * Create(uint32_t *data, uint32_t size);
    };

    class BufferLayout
    {
    public:
        BufferLayout(std::initializer_list<BufferElement> list);
        virtual ~BufferLayout() = default;

        static BufferLayout* Create(std::initializer_list<BufferElement> list);

    protected:
        std::vector<BufferElement> m_Elements;
        uint32_t m_Stride = 0;
    };
}

#endif