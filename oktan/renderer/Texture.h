#ifndef _OK_TEXTURE_H_
#define _OK_TEXTURE_H_

#include <string>

#include <oktan/Core.h>

namespace oktan
{
    enum class TextureType
    {
        Texture_2D,
    };

    enum class ColorType
    {
        Color_RGB,
        Color_RGBA,
    };

    class Texture
    {
    public:
        static Texture * Create(std::string path, TextureType type, ColorType color);

        virtual void Bind() = 0;
        virtual void Activate() = 0;

    protected:
        uint32_t m_Id = 0;
        int32_t m_Width = 0;
        int32_t m_Height = 0;
        int32_t m_NumChannels = 0;
        TextureType m_Type = TextureType::Texture_2D;
        ColorType m_Color = ColorType::Color_RGBA;
    };
}

#endif