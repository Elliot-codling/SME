#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

// ### Log colour codes ###
constexpr auto c_DEFAULT = "\033[39;49m";
constexpr auto c_GREY = "\033[90m"; // Trace
constexpr auto c_MAGENTA = "\033[95m"; // Debug
constexpr auto c_WHITE = "\033[97m"; // Info
constexpr auto c_YELLOW = "\033[93m"; // Warning
constexpr auto c_RED_WARNING = "\033[91m"; // Error
constexpr auto c_RED_FATAL = "\033[1;101m"; // Fatal

// TODO: Add a filter to show specific processes only
// TODO: Add a performance profiler
// Output layout
//[TIMESTAMP] [Process] [Log Level] : Content

enum class LogLevel {
    Trace,
    Debug,
    Info,
    Warn,
    Error,
    Fatal
};

class Logger
{
public:
    static void setMinLogLevel(LogLevel level) { minLevel = level; }

    template<LogLevel level, typename A, typename B>
    // Take in any value with templates
    static void log(const A &process, const B &content)
    {
        if (level < minLevel)
        {
            // Do not print anything under the specified log level
            return;
        }

        std::cout << getColor<level>()
                  << getTimestamp() << process << "] ["
                  << getLevelName<level>() << "] : "
                  << content << c_DEFAULT << std::endl;
    }

private:
    static inline LogLevel minLevel = LogLevel::Debug;

    // Declare the templates for the class to use
    template<LogLevel level>
    static constexpr const char* getLevelName();

    template<LogLevel level>
    static constexpr const char* getColor();

    static std::string getTimestamp();
};

// Get the log level name depending on which macro is called
template<>
constexpr const char* Logger::getLevelName<LogLevel::Trace>() { return "TRACE"; }
template<>
constexpr const char* Logger::getLevelName<LogLevel::Debug>() { return "DEBUG"; }
template<>
constexpr const char* Logger::getLevelName<LogLevel::Info>()  { return "INFO"; }
template<>
constexpr const char* Logger::getLevelName<LogLevel::Warn>()  { return "WARN"; }
template<>
constexpr const char* Logger::getLevelName<LogLevel::Error>() { return "ERROR"; }
template<>
constexpr const char* Logger::getLevelName<LogLevel::Fatal>() { return "FATAL"; }

// Change the colour depending on the macro used
template<>
constexpr const char* Logger::getColor<LogLevel::Trace>() { return c_GREY; }
template<>
constexpr const char* Logger::getColor<LogLevel::Debug>() { return c_MAGENTA; }
template<>
constexpr const char* Logger::getColor<LogLevel::Info>()  { return c_WHITE; }
template<>
constexpr const char* Logger::getColor<LogLevel::Warn>()  { return c_YELLOW; }
template<>
constexpr const char* Logger::getColor<LogLevel::Error>() { return c_RED_WARNING; }
template<>
constexpr const char* Logger::getColor<LogLevel::Fatal>() { return c_RED_FATAL; }


// Create a timestamp format
inline std::string Logger::getTimestamp() {
    using namespace std::chrono;
    // Get current time with high resolution
    const auto now = system_clock::now();

    // Convert to time_t for calendar time (seconds)
    const auto in_time_t = system_clock::to_time_t(now);

    // Extract milliseconds
    const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    // Format date and time
    const std::tm buffer = *std::localtime(&in_time_t);
    std::ostringstream output;
    output << "[" << std::put_time(&buffer, "%H:%M:%S")
        << "." << std::setfill('0') << std::setw(3) << milliseconds.count() << "] [";

    return output.str();


}

// ### Macro setup ###
#ifndef NDEBUG
#define LOG_TRACE(process, content)    Logger::log<LogLevel::Trace>(process, content)
#define LOG_DEBUG(process, content)    Logger::log<LogLevel::Debug>(process, content)
#define LOG_INFO(process, content)     Logger::log<LogLevel::Info>(process, content)
#define LOG_WARN(process, content)     Logger::log<LogLevel::Warn>(process, content)
#define LOG_ERROR(process, content)    Logger::log<LogLevel::Error>(process, content)
#define LOG_FATAL(process, content)    Logger::log<LogLevel::Fatal>(process, content)
#elif (_DEBUG)
#define LOG_TRACE(process, content)    Logger::log<LogLevel::Trace>(process, content)
#define LOG_DEBUG(process, content)    Logger::log<LogLevel::Debug>(process, content)
#define LOG_INFO(process, content)     Logger::log<LogLevel::Info>(process, content)
#define LOG_WARN(process, content)     Logger::log<LogLevel::Warn>(process, content)
#define LOG_ERROR(process, content)    Logger::log<LogLevel::Error>(process, content)
#define LOG_FATAL(process, content)    Logger::log<LogLevel::Fatal>(process, content)

// Remove macros if not in debug mode for gcc/clang/msvc
#else
#define LOG_TRACE(process, content)
#define LOG_DEBUG(process, content)
#define LOG_INFO(process, content)
#define LOG_WARN(process, content)
#define LOG_ERROR(process, content)
#define LOG_FATAL(process, content)
#endif

// TODO: Add assert