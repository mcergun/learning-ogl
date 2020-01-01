#ifndef _OK_OGL_SHADER_H_
#define _OK_OGL_SHADER_H_

#include <oktan/drawer/Shader.h>

namespace oktan
{
    class OGLShader : public Shader
    {
    public:
        OGLShader(const std::string & vertexPath, const std::string & fragmentPath);
        void Use();
        void SetUniform(const std::string & name, bool value);
        void SetUniform(const std::string & name, int32_t value);
        void SetUniform(const std::string & name, uint32_t value);
        void SetUniform(const std::string & name, float value);
        void SetUniform(const std::string & name, glm::mat4 & value);

    private:
        OGLShader() = default;
        bool IsCompileSuccessful(uint32_t shader);
        bool IsLinkSuccessful(uint32_t shader);
    };
}

#endif