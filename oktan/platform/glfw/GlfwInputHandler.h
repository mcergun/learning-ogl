#ifndef _OK_GLFW_INPUT_HANDLER_H_
#define _OK_GLFW_INPUT_HANDLER_H_

#include <GLFW/glfw3.h>
#include <ctype.h>

#include <oktan/Core.h>
#include <oktan/renderer/InputHandler.h>

namespace oktan
{
    class GlfwToOktan
    {
    public:
        static Keys ConvertKeyCode(int key);
        static Actions ConvertActions(int action);
    };

    class GlfwInputHandler : public InputHandler
    {
    public:
        GlfwInputHandler(GLFWwindow* win);
        virtual ~GlfwInputHandler();
        static void KeyCallback(GLFWwindow* win, int key, int scancode, int action, int mods);

    };
}

#endif
