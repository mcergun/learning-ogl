#ifndef _OK_LOGGER_H_
#define _OK_LOGGER_H_

#include "Core.h"
#include <string>

namespace oktan
{
    class Logger
    {
    public:
        static void Print(std::string str);
    };
}

#endif