#include <spdlog/include/spdlog/spdlog.h>
#include "Logger.h"

namespace oktan
{
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_AppLogger;

    void Logger::Initialize(LoggerLevel coreLvl, LoggerLevel appLvl)
    {
        s_CoreLogger = spdlog::stdout_color_mt("OKTAN");
        s_AppLogger = spdlog::stdout_color_mt("APP");
        spdlog::level::level_enum logLvl;
        switch (coreLvl)
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
        s_CoreLogger->set_level(logLvl);
        switch (appLvl)
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
        s_AppLogger->set_level(logLvl);
    }
}