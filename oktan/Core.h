#ifndef _OK_CORE_H_
#define _OK_CORE_H_

#include <cstdint>
#include <memory>

#include "Logger.h"

#define OK_OGL_ENABLED 1

namespace oktan
{
    enum class BaseType
    {
        Float,
        Float2,
        Float3,
        Int,
        Int2,
        Int3,
        UInt,
        UInt2,
        UInt3,
        Mat2,
        Mat3,
        Mat4,
        Vec2,
        Vec3,
        Vec4,
    };

    enum class BufferType
    {
        VertexBuffer,
        IndexBuffer,
    };
}

#endif