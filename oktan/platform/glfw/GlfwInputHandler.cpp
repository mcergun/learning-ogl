#include "GlfwInputHandler.h"

namespace oktan
{
    GlfwInputHandler::GlfwInputHandler(GLFWwindow *win) :
        m_Win(win)
    {
        glfwSetKeyCallback(m_Win, this->KeyCallback);
    }

    GlfwInputHandler::~GlfwInputHandler()
    {
        glfwSetKeyCallback(m_Win, nullptr);
    }

    void GlfwInputHandler::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
            OK_LOG_INFO("Callback {}, {}, {}", (char)key, scancode, mods);
    }
}