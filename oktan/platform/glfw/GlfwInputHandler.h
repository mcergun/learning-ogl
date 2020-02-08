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
        static Keys ConvertKeyCode(int key)
        {
            Keys ret = Keys::ASCII;
            if (!isascii(key))
            {
                switch (key)
                {
                case GLFW_KEY_ESCAPE:
                    ret = Keys::Escape;
                    break;
                case GLFW_KEY_ENTER:
                    ret = Keys::Enter;
                    break;
                case GLFW_KEY_TAB:
                    ret = Keys::Tab;
                    break;
                case GLFW_KEY_BACKSPACE:
                    ret = Keys::Backspace;
                    break;
                case GLFW_KEY_INSERT:
                    ret = Keys::Insert;
                    break;
                case GLFW_KEY_DELETE:
                    ret = Keys::Delete;
                    break;
                case GLFW_KEY_RIGHT:
                    ret = Keys::Right;
                    break;
                case GLFW_KEY_LEFT:
                    ret = Keys::Left;
                    break;
                case GLFW_KEY_DOWN:
                    ret = Keys::Down;
                    break;
                case GLFW_KEY_UP:
                    ret = Keys::Up;
                    break;
                case GLFW_KEY_HOME:
                    ret = Keys::Home;
                    break;
                case GLFW_KEY_END:
                    ret = Keys::End;
                    break;
                }
            }
            return ret;
        }
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
