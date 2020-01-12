#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlfwWindow.h"


namespace oktan
{
    GlfwWindow::GlfwWindow(uint32_t wid, uint32_t hei, std::string title) :
        Window(wid, hei, title)
    {
        int32_t res = glfwInit();
        GLFWwindow *win = NULL;
        OK_LOG_TRACE("glfwInit = {}", res);
        if (res == GLFW_TRUE)
        {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            win = glfwCreateWindow(wid, hei, title.c_str(), NULL, NULL);
        }
        if (res != GLFW_TRUE || win == NULL)
        {
            OK_LOG_ERROR("GLFW Window creation failed!");
            glfwTerminate();
        }
        else
        {
            OK_LOG_TRACE("Created a GLFW window with {} x {} size, titled \"{}\"", m_Width, m_Height, m_Title);
            winPtr = reinterpret_cast<char *>(win);
        }
    }

    int32_t GlfwWindow::Open()
    {
        glfwMakeContextCurrent(reinterpret_cast<GLFWwindow *>(winPtr));
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            OK_LOG_ERROR("gladLoadGLLoader failed!");
            return -1;
        }
        OK_LOG_TRACE("Loaded GLAD");
        return 0;
    }

}