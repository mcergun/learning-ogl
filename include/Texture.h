#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>

enum TextureType
{
    Texture_2D,
};

class Texture
{
public:
    Texture(TextureType type, std::string path);

private:
    unsigned int Id = 0;
    int Width = 0;
    int Height = 0;
    int NChannels = 0;
};

#endif