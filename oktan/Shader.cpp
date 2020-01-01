#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include "platform/opengl/OGLShader.h"

namespace oktan
{
    Shader * Shader::Create(const std::string & vertexPath, const std::string & fragmentPath)
    {
    #if OK_OGL_ENABLED == 1
        return new OGLShader(vertexPath, fragmentPath);
    #else
        return nullptr;
    #endif
    }
}

#if 0
Shader::Shader(const std::string & vertexPath, const std::string & fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream ifs;
    ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        ifs.open(vertexPath);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        vertexCode = ss.str();
        ss.str("");
        ss.clear();

        ifs.open(fragmentPath);
        ss << ifs.rdbuf();
        ifs.close();
        fragmentCode = ss.str();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    const char * vertexCodePtr = vertexCode.c_str();
    const char * fragmentCodePtr = fragmentCode.c_str();
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
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        IsLinkSuccessful(ID);
    }
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetUniform(const std::string & name, bool value) const
{
    int varLoc = glGetUniformLocation(ID, name.c_str());
    glUniform1i(varLoc, value);
}

void Shader::SetUniform(const std::string & name, int value) const
{
    int varLoc = glGetUniformLocation(ID, name.c_str());
    glUniform1i(varLoc, value);
}

void Shader::SetUniform(const std::string & name, float value) const
{
    int varLoc = glGetUniformLocation(ID, name.c_str());
    glUniform1f(varLoc, value);
}

void Shader::SetUniform(const std::string & name, glm::mat4 & value) const
{
    int varLoc = glGetUniformLocation(ID, name.c_str());
    glUniformMatrix4fv(varLoc, 1, GL_FALSE, glm::value_ptr(value));
}

bool Shader::IsCompileSuccessful(unsigned int shader)
{
    bool ret = true;
    int success;
    char log[512] = {0};
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success == 0)
    {
        glGetShaderInfoLog(shader, sizeof(log), NULL, log);
        std::cout << log << std::endl;
        ret = false;
    }
    
    return ret;
}

bool Shader::IsLinkSuccessful(unsigned int shader)
{
    bool ret = true;
    int success;
    char log[512] = {0};
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (success != 0)
    {
        glGetProgramInfoLog(shader, sizeof(log), NULL, log);
        std::cout << log << std::endl;
        ret = false;
    }
    return ret;
}
#endif
