#ifndef _OK_GLFW_WINDOW_H_
#define _OK_GLFW_WINDOW_H_

#include <oktan/renderer/Window.h>

namespace oktan
{
    class GlfwWindow : public Window
    {
    public:
        GlfwWindow(uint32_t wid, uint32_t hei, std::string title);
        int32_t Open();

    private:
        // unsafe method for keeping window pointer
        char *winPtr = nullptr;
    };
};

#endif