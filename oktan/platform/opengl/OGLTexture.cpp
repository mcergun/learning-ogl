#include <glad/glad.h>
#include <stb_image.h>

#include "OGLTexture.h"

namespace oktan
{
    static GLenum ConvertToGL(ColorType color);
    static GLenum ConvertToGL(TextureType tex);

    OGLTexture::OGLTexture(std::string path, TextureType type, ColorType color)
    {
        m_Type = type;
        m_Color = color;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_NumChannels, 0);
        if (data)
        {
            glGenTextures(1, &m_Id);
            OK_LOG_TRACE("Created Texture {}, {} dimensions: {} x {}", m_Id, path, m_Width, m_Height);
            GLenum texEnum = ConvertToGL(m_Type);
            GLenum colEnum = ConvertToGL(m_Color);
            glBindTexture(texEnum, m_Id);
            glTexParameteri(texEnum, GL_TEXTURE_WRAP_S, GL_REPEAT);	
            glTexParameteri(texEnum, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(texEnum, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(texEnum, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(texEnum, 0, colEnum, m_Width, m_Height, 0, colEnum, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(texEnum);
            stbi_image_free(data);
        }
        else
        {
            OK_LOG_ERROR("Texture can't be loaded from {} : {}", path, stbi_failure_reason());
        }
    }

    void OGLTexture::Bind()
    {
        GLenum texEnum = ConvertToGL(m_Type);
        glBindTexture(texEnum, m_Id);
    }

    void OGLTexture::Activate()
    {
        glActiveTexture(GL_TEXTURE0 + m_Id);
    }

    GLenum ConvertToGL(ColorType color)
    {
        GLenum ret;
        switch (color)
        {
        case ColorType::Color_RGBA:
            ret = GL_RGBA;
            break;
        case ColorType::Color_RGB:
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
        case TextureType::Texture_2D:
        default:
            ret = GL_TEXTURE_2D;
            break;
        }
        return ret;
    }
}