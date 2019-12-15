#include <spdlog/include/spdlog/spdlog.h>
#include "Logger.h"

namespace oktan
{
    void Logger::Print(std::string str)
    {
        spdlog::info("Hello, {}!", "World");
    }
}