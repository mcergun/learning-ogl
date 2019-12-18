#include <spdlog/include/spdlog/spdlog.h>
#include "Logger.h"

namespace oktan
{
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_AppLogger;

    spdlog::level::level_enum ConvertToSpdLevel(LoggerLevel lvl)
    {
        spdlog::level::level_enum logLvl;
        switch (lvl)
        {
        case LoggerLevel::Trace:
            logLvl = spdlog::level::trace;
            break;
        case LoggerLevel::Debug:
            logLvl = spdlog::level::debug;
            break;
        case LoggerLevel::Info:
            logLvl = spdlog::level::info;
            break;
        case LoggerLevel::Warning:
            logLvl = spdlog::level::warn;
            break;
        case LoggerLevel::Error:
            logLvl = spdlog::level::err;
            break;
        case LoggerLevel::Critical:
            logLvl = spdlog::level::critical;
            break;
        case LoggerLevel::Off:
        default:
            logLvl = spdlog::level::off;
            break;
        }
        return logLvl;
    }

    void Logger::Initialize(LoggerLevel coreLvl, LoggerLevel appLvl)
    {
        s_CoreLogger = spdlog::stdout_color_mt("OKTAN");
        s_AppLogger = spdlog::stdout_color_mt("APP");
        auto logLvl = ConvertToSpdLevel(coreLvl);
        s_CoreLogger->set_level(logLvl);
        logLvl = ConvertToSpdLevel(appLvl);
        s_AppLogger->set_level(logLvl);
    }
}