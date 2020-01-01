#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Core.h"

namespace oktan
{
    class Shader
    {
    public:
        virtual ~Shader() = default;
        virtual void Use();
        virtual void SetUniform(const std::string & name, bool value) = 0;
        virtual void SetUniform(const std::string & name, int32_t value) = 0;
        virtual void SetUniform(const std::string & name, uint32_t value) = 0;
        virtual void SetUniform(const std::string & name, float value) = 0;
        virtual void SetUniform(const std::string & name, glm::mat4 & value) = 0;
        static Shader * Create(const std::string & vertexPath, const std::string & fragmentPath);

    protected:
        Shader(const std::string & vertexPath, const std::string & fragmentPath) :
            m_VtxShaderPath(vertexPath), m_FragShaderPath(fragmentPath)
        {}

        uint32_t m_Id;
        std::string m_VtxShaderPath;
        std::string m_FragShaderPath;

    private:
        Shader() = default;
    };
}

// class Shader
// {
// public:
//     unsigned int ID;
//     Shader(const std::string & vertexPath, const std::string & fragmentPath);
//     void Use();
//     void SetUniform(const std::string & name, bool value) const;
//     void SetUniform(const std::string & name, int value) const;
//     void SetUniform(const std::string & name, float value) const;
//     void SetUniform(const std::string &name, glm::mat4 & value) const;

// private:
//     bool IsCompileSuccessful(unsigned int shader);
//     bool IsLinkSuccessful(unsigned int shader);
// };

#endif // _SHADER_H_