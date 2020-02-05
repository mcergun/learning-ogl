#ifndef _OK_GLFW_INPUT_HANDLER_H_
#define _OK_GLFW_INPUT_HANDLER_H_

#include <GLFW/glfw3.h>

#include <oktan/Core.h>

namespace oktan
{
    class GlfwInputHandler
    {
    public:
        GlfwInputHandler(GLFWwindow *win);
        virtual ~GlfwInputHandler();
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    private:
        GLFWwindow *m_Win;
    };
}

#endif
