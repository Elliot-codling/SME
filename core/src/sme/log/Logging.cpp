#include <sme/log/Logging.h>

// Filter out messages depending on the configuration at startup
bool Logger::filterMessages(const LogLevel level, const std::string &key)
{
    // Return true to print message else return false
    if (level < m_minLevel)
    {
        // Do not print anything under the specified log level
        return false;
    }

    // Check if it is not unique
    if (!m_loggedMessages.insert(key).second)
    {
        // Check if level is not Trace
        if (level != LogLevel::Trace)
        {
            return false;
        }
        // Check if repeat message is not true
        if (!m_repeatTraceMessages)
        {
            return false;
        }
    }
    return true;
}
