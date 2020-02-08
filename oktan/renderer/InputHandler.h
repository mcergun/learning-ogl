#ifndef _OK_INPUT_HANDLER_H_
#define _OK_INPUT_HANDLER_H_

#include <oktan/Core.h>
#include <oktan/renderer/Window.h>

namespace oktan
{
    enum class Modifiers
    {
        Ctrl,
        Alt,
        Shift,
        CtrlAlt,
        CtrlShift,
        AltShift,
        CtrlAltShift,
    };

    enum class Actions
    {
        KeyDown,
        KeyUp,
        Continuous,
    };

    enum class Keys
    {
        ASCII,
        Escape,
        Enter,
        Tab,
        Backspace,
        Insert,
        Delete,
        Right,
        Left,
        Down,
        Up,
        Home,
        End,
        F1, F2, F3, F4,
        F5, F6, F7, F8,
        F9, F10, F11, F12,
        // TODO: Add missing keys (have a lot of them !!!)
    };

    typedef void (*KeyCallbackFunction)(Keys, int, Modifiers, Actions);

    class InputHandler
    {
    public:
        static InputHandler* Create(Window *win);
        virtual ~InputHandler() = default;
        virtual void SetKeyCallback(KeyCallbackFunction fn);
    protected:
        KeyCallbackFunction f_KeyCb;
    };
}

#endif