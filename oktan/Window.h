#ifndef _OK_WINDOW_H_
#define _OK_WINDOW_H_

#include <string>

#include "Core.h"

namespace oktan
{
    class Window
    {
    public:
        virtual ~Window() = default;
        virtual int32_t Open() = 0;

        static Window * Create(uint32_t wid, uint32_t hei, std::string title);

    protected:
        Window() = default;
        Window(uint32_t wid, uint32_t hei, std::string title);

        uint32_t m_Width = 0;
        uint32_t m_Height = 0;
        std::string m_Title = "";
    };
};

#endif