#ifndef _OK_GLFW_WINDOW_H_
#define _OK_GLFW_WINDOW_H_

#include <GLFW/glfw3.h>

#include <oktan/renderer/Window.h>

namespace oktan
{
    class GlfwWindowImpl : public Window
    {
    public:
        GlfwWindowImpl(uint32_t wid, uint32_t hei, std::string title);
        int32_t Open() override;
        bool ShouldClose() override;
        void SwapBuffers() override;

    private:
        // unsafe method for keeping window pointer
        GLFWwindow *m_Win = nullptr;

        // Inherited via Window
    };
};

#endif