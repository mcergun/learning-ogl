#ifndef _OK_OGL_SHADER_H_
#define _OK_OGL_SHADER_H_

#include <unordered_map>
#include <oktan/Core.h>
#include <oktan/renderer/Shader.h>

namespace oktan
{
    class OGLShader : public Shader
    {
    public:
        OGLShader(const std::string & vertexPath, const std::string & fragmentPath);
        void Use();
        void SetUniform(const std::string & name, const bool value);
        void SetUniform(const std::string & name, const int32_t value);
        void SetUniform(const std::string & name, const uint32_t value);
        void SetUniform(const std::string & name, const float value);
        void SetUniform(const std::string & name, const glm::mat4 & value);

    private:
        OGLShader() = default;
        bool IsCompileSuccessful(uint32_t shader);
        bool IsLinkSuccessful(uint32_t shader);
        bool GetUniformCache(std::string name, int32_t &loc);
        void AddToUniformCache(std::string name, int32_t &loc);

        std::unordered_map<std::string, int32_t> m_UniformDict;
    };
}

#endif