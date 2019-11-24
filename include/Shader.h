#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;
    Shader(const std::string & vertexPath, const std::string & fragmentPath);
    void Use();
    void SetUniform(const std::string & name, bool value) const;
    void SetUniform(const std::string & name, int value) const;
    void SetUniform(const std::string & name, float value) const;

private:
    bool IsCompileSuccessful(unsigned int shader);
    bool IsLinkSuccessful(unsigned int shader);
};

#endif // _SHADER_H_