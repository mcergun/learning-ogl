#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <oktan/platform/opengl/OGLShader.h>

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