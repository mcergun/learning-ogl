#ifndef _OK_OGL_TEXTURE_H_
#define _OK_OGL_TEXTURE_H_

#include <vector>
#include <oktan/Core.h>
#include <oktan/renderer/Texture.h>

namespace oktan
{
    class OGLTexture : public Texture
    {
    public:
        OGLTexture(std::string path, TextureType type, ColorType color, uint32_t slot);
        OGLTexture(std::string path, TextureType type, ColorType color);
        ~OGLTexture();
        void Bind() override;
        void Assign(uint32_t slot) override;

        static int32_t GetNextSlot();
        static void PrepareSlots();

    private:
        static std::vector<bool> s_AvailableSlots;
        static int32_t s_MaxTextureCount;

        int32_t m_Slot = 0;
    };
}

#endif