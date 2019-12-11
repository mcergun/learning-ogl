#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>

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
    Texture(std::string path, TextureType type, ColorType color);
    void Bind();

    static void Activate(unsigned int n);

private:
    unsigned int Id = 0;
    TextureType Type = Texture_2D;
    ColorType Color = Color_RGB;
    int Width = 0;
    int Height = 0;
    int NChannels = 0;
};

#endif