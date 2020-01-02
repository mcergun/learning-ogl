#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>

#include <oktan/Core.h>

namespace oktan
{
    enum TextureType
    {
        Texture_2D,
    };

    enum ColorType
    {
        Color_RGB,
        Color_RGBA,
    };

    class Texture
    {
    public:
        static Texture * Create(std::string path, TextureType type, ColorType color);
    };
}


class Texture
{
public:
    void Bind();
    virtual void Activate(unsigned int n) = 0;

    static Texture * Create(std::string path, TextureType type, ColorType color);

protected:
    Texture(std::string path, TextureType type, ColorType color);
    unsigned int Id = 0;
    TextureType Type = Texture_2D;
    ColorType Color = Color_RGB;
    int Width = 0;
    int Height = 0;
    int NChannels = 0;

private:
    Texture() = default;
};

#endif