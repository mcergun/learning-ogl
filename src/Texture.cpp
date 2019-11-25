#include <Texture.h>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

GLenum ConvertToGL(ColorType color)
{
    GLenum ret;
    switch (color)
    {
    case Color_RGBA:
        ret = GL_RGBA;
        break;
    case Color_RGB:
    default:
        ret = GL_RGB;
        break;
    }
    return ret;
}

GLenum ConvertToGL(TextureType tex)
{
    GLenum ret;
    switch (tex)
    {
    case Texture_2D:
    default:
        ret = GL_TEXTURE_2D;
        break;
    }
    return ret;
}

Texture::Texture(std::string path, TextureType type, ColorType color) :
    Type(type), Color(color)
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path.c_str(), &Width, &Height, &NChannels, 0);
    if (data)
    {
        glGenTextures(1, &Id);
        std::cout << Id << " is generated with " << path << std::endl;
        std::cout << "Width = " << Width << ", Height = " << Height << std::endl;
        GLenum texEnum = ConvertToGL(Type);
        GLenum colEnum = ConvertToGL(Color);
        glBindTexture(texEnum, Id);
        glTexParameteri(texEnum, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	    glTexParameteri(texEnum, GL_TEXTURE_WRAP_T, GL_REPEAT);
	    glTexParameteri(texEnum, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(texEnum, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(texEnum, 0, colEnum, Width, Height, 0, colEnum, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(texEnum);
        stbi_image_free(data);
    }
}

void Texture::Bind()
{
    GLenum texEnum = ConvertToGL(Type);
    glBindTexture(texEnum, Id);
}

void Texture::Activate(unsigned int n)
{
    glActiveTexture(GL_TEXTURE0 + n);
}