#include <glad/glad.h>

#include "GlfwWindow.h"


namespace oktan
{
    GlfwWindowImpl::GlfwWindowImpl(uint32_t wid, uint32_t hei, std::string title) :
        Window(wid, hei, title)
    {
        int32_t res = glfwInit();
        OK_LOG_TRACE("glfwInit = {}", res);
        if (res == GLFW_TRUE)
        {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }
        else
        {
            OK_LOG_ERROR("GLFW init failed!");
            glfwTerminate();
        }
    }

    int32_t GlfwWindowImpl::Open()
    {
        int32_t ret = -1;
        m_Win = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
        if (m_Win != NULL)
        {
            OK_LOG_TRACE("Created a GLFW window with {} x {} size, titled \"{}\"", m_Width, m_Height, m_Title);
            glfwMakeContextCurrent(m_Win);
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                OK_LOG_ERROR("gladLoadGLLoader failed!");
            }
            else
            {
                OK_LOG_TRACE("Loaded GLAD");
                ret = 0;
            }
        }
        else
        {
            OK_LOG_ERROR("GLFW window creation failed!");
        }
        if (ret != 0)
        {
            glfwTerminate();
        }
        return ret;
    }

    bool GlfwWindowImpl::ShouldClose()
    {
        return glfwWindowShouldClose(m_Win);
    }

    void GlfwWindowImpl::SwapBuffers()
    {
        glfwSwapBuffers(m_Win);
    }

}