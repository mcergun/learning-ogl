#ifndef _OK_OGL_TEXTURE_H_
#define _OK_OGL_TEXTURE_H_

#include <oktan/Core.h>
#include <oktan/renderer/Texture.h>

namespace oktan
{
    class OGLTexture : public Texture
    {
    public:
        OGLTexture(std::string path, TextureType type, ColorType color, uint32_t slot);
        void Bind() override;
        void Assign(uint32_t slot) override;
    };
}

#endif