#include <Texture.h>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(TextureType type, std::string path)
{
    unsigned char *data = stbi_load(path.c_str(), &Width, &Height, &NChannels, 0);
    if (data)
    {
        glGenTextures(1, &Id);
        GLuint texEnum;
        switch (type)
        {
        case Texture_2D:
        default:
            texEnum = GL_TEXTURE_2D;
            break;
        }
        glBindTexture(Id, texEnum);
        glTexParameteri(texEnum, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	    glTexParameteri(texEnum, GL_TEXTURE_WRAP_T, GL_REPEAT);
	    glTexParameteri(texEnum, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(texEnum, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(texEnum, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(texEnum);
        stbi_image_free(data);
    }
}