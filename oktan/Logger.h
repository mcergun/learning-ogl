#ifndef _OK_LOGGER_H_
#define _OK_LOGGER_H_

#include "Core.h"
#include "vendor/spdlog/include/spdlog/spdlog.h"
#include <string>

namespace oktan
{
    enum class LoggerLevel
    {
        Off,
        Trace,
        Debug,
        Info,
        Warning,
        Error,
        Critical,
    };

    class Logger
    {
    public:
        static void Initialize(LoggerLevel coreLvl, LoggerLevel appLvl);

        static inline std::shared_ptr<spdlog::logger> GetCoreLogger()
        {
            return s_CoreLogger;
        }

        static inline std::shared_ptr<spdlog::logger> GetAppLogger()
        {
            return s_AppLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_AppLogger;
    };
}

#define OK_LOG_TRACE(...)   ::oktan::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define OK_LOG_INFO(...)   ::oktan::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define OK_LOG_DEBUG(...)   ::oktan::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define OK_LOG_WARN(...)   ::oktan::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define OK_LOG_ERROR(...)   ::oktan::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define OK_LOG_CRIT(...)   ::oktan::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define OK_APP_LOG_TRACE(...)   ::oktan::Logger::GetAppLogger()->trace(__VA_ARGS__)
#define OK_APP_LOG_INFO(...)   ::oktan::Logger::GetAppLogger()->info(__VA_ARGS__)
#define OK_APP_LOG_DEBUG(...)   ::oktan::Logger::GetAppLogger()->debug(__VA_ARGS__)
#define OK_APP_LOG_WARN(...)   ::oktan::Logger::GetAppLogger()->warn(__VA_ARGS__)
#define OK_APP_LOG_ERROR(...)   ::oktan::Logger::GetAppLogger()->error(__VA_ARGS__)
#define OK_APP_LOG_CRIT(...)   ::oktan::Logger::GetAppLogger()->critical(__VA_ARGS__)

#endif