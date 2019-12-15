#include <iostream>
#include "Logger.h"

namespace oktan
{
    void Logger::Print(std::string str)
    {
        std::cout << str;
    }
}