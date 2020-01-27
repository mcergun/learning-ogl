#include "Texture.h"
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>
#include <oktan/platform/opengl/OGLTexture.h>

namespace oktan
{
    Texture * Texture::Create(std::string path, TextureType type, ColorType color, uint32_t slot)
    {
#if OK_OGL_ENABLED == 1
        return new OGLTexture(path, type, color, slot);
#else
        return nullptr;
#endif
    }
}
