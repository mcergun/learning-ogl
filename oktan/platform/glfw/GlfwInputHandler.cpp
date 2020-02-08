#include "GlfwInputHandler.h"

namespace oktan
{
    GlfwInputHandler::GlfwInputHandler(GLFWwindow* win)
    {
        glfwSetWindowUserPointer(win, this);
        glfwSetKeyCallback(win, KeyCallback);
    }

    GlfwInputHandler::~GlfwInputHandler()
    {

    }

    void GlfwInputHandler::KeyCallback(GLFWwindow* win, int key, int scancode, int action, int mods)
    {
        GlfwInputHandler *inp =
            reinterpret_cast<GlfwInputHandler *>(glfwGetWindowUserPointer(win));
        inp->f_KeyCb(GlfwToOktan::ConvertKeyCode(key), key, Modifiers::Alt,
            Actions::KeyDown);
        
    }
}