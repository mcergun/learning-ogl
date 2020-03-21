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
        VertexData() = default;
        float PosX = 0.0f;
        float PosY = 0.0f;
        float PosZ = 0.0f;
        float TexPosX = 0.0f;
        float TexPosY = 0.0f;
    };

    struct QuadData
    {
    public:
        QuadData(float botleftx, float botlefty, float toprightx, float toprighty)
        {
            Vertices[0] = {botleftx, botlefty, 1.0f, 0.0f, 0.0f};
            Vertices[1] = {botleftx, toprighty, 1.0f, 0.0f, 1.0f};
            Vertices[2] = {toprightx, toprighty, 1.0f, 1.0f, 1.0f};
            Vertices[3] = {toprightx, botlefty, 1.0f, 1.0f, 0.0f};
        }
        VertexData Vertices[4];
    };
}

#endif