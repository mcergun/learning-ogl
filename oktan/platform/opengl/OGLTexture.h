#ifndef _OK_OGL_TEXTURE_H_
#define _OK_OGL_TEXTURE_H_

#include <oktan/renderer/Texture.h>
#include <oktan/Logger.h>

namespace oktan
{
    class OGLTexture : public Texture
    {
    public:
        OGLTexture(std::string path, TextureType type, ColorType color);
        void Bind() override;
        void Activate() override;
    };
}

#endif