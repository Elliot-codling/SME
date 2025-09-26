#pragma once

#include <sme/log/Logging.h>
#include <chrono>
#include <fmt/format.h>

class Profiler
{
public:
    // ### Stop watch controls ###
    static void startWatch();
    static void stopWatchAndPrintResult(const std::string &process);

private:
    // Variables
    static inline std::chrono::time_point<std::chrono::system_clock> start;
    static inline std::chrono::time_point<std::chrono::system_clock> end;
};

// ### Macro setup ###
#ifndef NDEBUG
#define START_WATCH()           Profiler::startWatch();
#define STOP_WATCH(process)     Profiler::stopWatchAndPrintResult(process);
#elif _DEBUG
#define START_WATCH()           Profiler::startWatch();
#define STOP_WATCH(process)     Profiler::stopWatchAndPrintResult(process);

// Remove macros if not in debug mode
#else
#define START_WATCH()
#define STOP_WATCH(process)
#endif