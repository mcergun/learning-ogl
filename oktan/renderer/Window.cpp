#include "Window.h"
#include <oktan/platform/glfw/GlfwWindow.h>

namespace oktan
{
    Window * Window::Create(uint32_t wid, uint32_t hei, std::string title)
    {
    #if OK_OGL_ENABLED == 1
        return new GlfwWindow(wid, hei, title);
    #else
        return nullptr;
    #endif
    }

    Window::Window(uint32_t wid, uint32_t hei, std::string title) :
        m_Width(wid), m_Height(hei), m_Title(title)
    {

    }
};