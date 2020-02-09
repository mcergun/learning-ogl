#include "GlfwInputHandler.h"

namespace oktan
{
    Keys GlfwToOktan::ConvertKeyCode(int key)
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
            default:
                ret = Keys::UnknownKey;
                break;
            }
        }
        return ret;
    }
    
    Actions GlfwToOktan::ConvertActions(int action)
    {
        Actions act;
        switch (action)
        {
        case GLFW_RELEASE:
            act = Actions::KeyUp;
            break;
        case GLFW_PRESS:
            act = Actions::KeyDown;
            break;
        case GLFW_REPEAT:
            act = Actions::Continuous;
            break;
        default:
            act = Actions::UnknownAction;
            break;
        }
        return act;
    }


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
            GlfwToOktan::ConvertActions(action));
        
    }
}