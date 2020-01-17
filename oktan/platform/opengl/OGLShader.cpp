#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <oktan/FileLoader.h>

#include "OGLShader.h"

namespace oktan
{
    OGLShader::OGLShader(const std::string & vertexPath, const std::string & fragmentPath) :
        Shader(vertexPath, fragmentPath)
    {
        std::string vtxCode;
        std::string fragCode;
        if (FileLoader::ReadFile(vertexPath, vtxCode) == 0 &&
            FileLoader::ReadFile(fragmentPath, fragCode) == 0)
        {
            OK_LOG_TRACE("Shaders have been loaded.");
            const char * vertexCodePtr = vtxCode.c_str();
            const char * fragmentCodePtr = fragCode.c_str();
            unsigned int vertex;
            unsigned int fragment;

            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vertexCodePtr, NULL);
            glCompileShader(vertex);

            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fragmentCodePtr, NULL);
            glCompileShader(fragment);
            
            if (IsCompileSuccessful(vertex) && IsCompileSuccessful(fragment))
            {
                m_Id = glCreateProgram();
                glAttachShader(m_Id, vertex);
                glAttachShader(m_Id, fragment);
                glLinkProgram(m_Id);
                IsLinkSuccessful(m_Id);
            }
            glDeleteShader(vertex);
            glDeleteShader(fragment);
        }
        else
        {
            OK_LOG_CRIT("Shaders can't be loaded!");
        }
    }


    bool OGLShader::IsCompileSuccessful(uint32_t shader)
    {
        bool ret = true;
        int32_t success;
        char log[512] = {0};
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success == 0)
        {
            glGetShaderInfoLog(shader, sizeof(log), NULL, log);
            OK_LOG_CRIT("Shader compilation failed for {} with : {}", shader, log);
            ret = false;
        }
        
        return ret;
    }

    bool OGLShader::IsLinkSuccessful(uint32_t shader)
    {
        bool ret = true;
        int success;
        char log[512] = {0};
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (success == 0)
        {
            glGetProgramInfoLog(shader, sizeof(log), NULL, log);
            OK_LOG_CRIT("Shader linking failed for {} with : {}", shader, log);
            ret = false;
        }
        return ret;
    }

    bool OGLShader::GetUniformCache(std::string name, int32_t &loc)
    {
        auto search = m_UniformDict.find(name);
        bool found = search != m_UniformDict.end();
        if (found)
        {
            loc = search->second;
            OK_LOG_TRACE("Uniform {} is already cached, location = {}", name, loc);
        }
        
        return found;
    }

    void OGLShader::AddToUniformCache(std::string name, int32_t & loc)
    {
        // Save the value into the dictionary
        loc = glGetUniformLocation(m_Id, name.c_str());
        if (loc != -1)
        {
            OK_LOG_TRACE("Adding uniform {} to cache, location = {}", name, loc);
            m_UniformDict.insert({name, loc});
        }
    }

    void OGLShader::Use()
    {
        glUseProgram(m_Id);
    }
    
    void OGLShader::SetUniform(const std::string & name, bool value)
    {
        int32_t loc = -1;
        if (!GetUniformCache(name, loc))
        {
            AddToUniformCache(name, loc);
        }
        if (loc != -1)
        {
            glUniform1i(loc, value);
            OK_LOG_TRACE("Set uniform {}'s value to {}", name, value);
        }
        else
        {
            OK_LOG_ERROR("Uniform {} can't be found in the shader", name);
        }
    }
    
    void OGLShader::SetUniform(const std::string & name, int32_t value)
    {
        int32_t loc = -1;
        if (!GetUniformCache(name, loc))
        {
            AddToUniformCache(name, loc);
        }
        if (loc != -1)
        {
            glUniform1i(loc, value);
            OK_LOG_TRACE("Set uniform {}'s value to {}", name, value);
        }
        else
        {
            OK_LOG_ERROR("Uniform {} can't be found in the shader", name);
        }
    }
    
    void OGLShader::SetUniform(const std::string & name, uint32_t value)
    {
        int32_t loc = -1;
        if (!GetUniformCache(name, loc))
        {
            AddToUniformCache(name, loc);
        }
        if (loc != -1)
        {
            glUniform1ui(loc, value);
            OK_LOG_TRACE("Set uniform {}'s value to {}", name, value);
        }
        else
        {
            OK_LOG_ERROR("Uniform {} can't be found in the shader", name);
        }
    }
    
    void OGLShader::SetUniform(const std::string & name, float value)
    {
        int32_t loc = -1;
        if (!GetUniformCache(name, loc))
        {
            AddToUniformCache(name, loc);
        }
        if (loc != -1)
        {
            glUniform1f(loc, value);
            OK_LOG_TRACE("Set uniform {}'s value to {}", name, value);
        }
        else
        {
            OK_LOG_ERROR("Uniform {} can't be found in the shader", name);
        }
    }
    
    void OGLShader::SetUniform(const std::string & name, glm::mat4 & value)
    {
        int32_t loc = -1;
        if (!GetUniformCache(name, loc))
        {
            AddToUniformCache(name, loc);
        }
        if (loc != -1)
        {
            glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
            // Don't print out matrix' value
            OK_LOG_TRACE("Set uniform {}'s value", name);
        }
        else
        {
            OK_LOG_ERROR("Uniform {} can't be found in the shader", name);
        }
    }
    

}