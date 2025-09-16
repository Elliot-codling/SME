#include "Runtime.h"
#include "../include/MainScript.h"
Runtime::Runtime(const char* titleName, const int width, const int height)
{
    LOG_TRACE("Runtime.h", "'Runtime::Runtime' requested.");
    LOG_TRACE("Runtime.h", "Attempting to create window...");
    // Create the window and start the mainScript
    if (!m_app.createWindow(titleName, width, height))
    {
        LOG_TRACE("Runtime.h", "runtimeState::start aborted.");
        return;
    }
    LOG_TRACE("Runtime.h", "Entering 'runtimeState::start'");
    runtimeState::start(m_app);
}

void Runtime::update()
{
    LOG_TRACE("Runtime.h", "'Runtime::update' requested.");
    // Game loop
    while (m_app.isRunning())
    {
        m_timeElapsed = m_clock.restart();
        m_timeSinceLastUpdate += m_timeElapsed.asSeconds();

        //std::cout << m_timeElapsed.asMilliseconds() << std::endl;

        while (m_timeSinceLastUpdate >= c_fixedTime)
        {
            LOG_TRACE("Runtime.h", "Entering 'runtimeState::fixedUpdate'");
            runtimeState::fixedUpdate(m_app, c_fixedTime);
            // Update current frametime
            //m_app.setFrametime(m_timeElapsed.asSeconds());
            m_timeSinceLastUpdate -= c_fixedTime;
        }
        LOG_TRACE("Runtime.h", "Entering 'runtimeState::update'");
        runtimeState::update(m_app, m_timeElapsed.asSeconds());
    }
    LOG_TRACE("Runtime.h", "'isRunning()' returned false");
}

void Runtime::end()
{
    LOG_TRACE("Runtime.h", "Entering 'runtimeState::end'");
    runtimeState::end();
}