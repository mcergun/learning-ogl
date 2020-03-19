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
        Byte,
        UByte,
        Short,
        UShort,
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

    // Struct that holds generic vertex data:
    //  - Vertex Coordinates (X, Y, Z)
    //  - Texture Coordinates (X, Y)
    struct VertexData
    {
    public:
        VertexData(float posx, float posy, float posz, float texposx, float texposy) :
            PosX(posx), PosY(posy), PosZ(posz), TexPosX(texposx), TexPosY(texposy) {}
        float PosX = 0.0f;
        float PosY = 0.0f;
        float PosZ = 0.0f;
        float TexPosX = 0.0f;
        float TexPosY = 0.0f;
    private:
        // Hide default constructor, we don't need it
        VertexData() = default;
    };
}

#endif