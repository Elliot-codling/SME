#include <sme/log/Profiler.h>

void Profiler::startWatch()
{
    using namespace std::chrono;
    start = system_clock::now();
}

void Profiler::stopWatchAndPrintResult(const std::string &process)
{
    using namespace std::chrono;
    end = system_clock::now();
    const duration<double> timeElapsed = end - start;
    LOG_DEBUG(process, fmt::format("Computation completed in: {}", timeElapsed.count()));
}
