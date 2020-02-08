#include "InputHandler.h"
#include <oktan/platform/glfw/GlfwWindow.h>
#include <oktan/platform/glfw/GlfwInputHandler.h>

namespace oktan
{
    InputHandler* InputHandler::Create(Window *win)
    {
#if OK_OGL_ENABLED == 1
        GlfwWindowImpl *winImpl = reinterpret_cast<GlfwWindowImpl *>(win);
        return new GlfwInputHandler(winImpl->GetWindowPointer());
#else
        return nullptr;
#endif
    }
    void InputHandler::SetKeyCallback(KeyCallbackFunction fn)
    {
        f_KeyCb = fn;
    }

}