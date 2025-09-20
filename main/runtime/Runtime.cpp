#include "Runtime.h"
#include "../include/MainScript.h"
Runtime::Runtime(const char* titleName, const int width, const int height)
{
    LOG_TRACE("runtime/Runtime.cpp", "Creating 'Runtime'");
    LOG_TRACE("runtime/Runtime.cpp", "Attempting to create window...");
    // Create the window and start the mainScript
    if (!m_app.createWindow(titleName, width, height))
    {
        LOG_TRACE("runtime/Runtime.cpp", "runtimeState::start aborted.");
        return;
    }
    runtimeState::start(m_app);
}

void Runtime::update()
{
    LOG_TRACE("runtime/Runtime.cpp", "'update()' requested");
    // Game loop
    while (m_app.isRunning())
    {
        m_timeElapsed = m_clock.restart();
        m_timeSinceLastUpdate += m_timeElapsed.asSeconds();

        m_app.updateEvents();
        while (m_timeSinceLastUpdate >= c_fixedTime)
        {
            runtimeState::fixedUpdate(m_app, c_fixedTime);
            // Update current frametime
            //m_app.setFrametime(m_timeElapsed.asSeconds());
            m_timeSinceLastUpdate -= c_fixedTime;
        }
        runtimeState::update(m_app, m_timeElapsed.asSeconds());
        if (m_app.getActiveScene() == nullptr)
        {
            // Execute a safe shutdown
            LOG_FATAL("runtime/Runtime.cpp", "No active scene present. Aborting.");
            m_app.stopRunning();
            return;
        }
        m_app.updateDisplay();
    }
}

void Runtime::end()
{
    LOG_TRACE("runtime/Runtime.cpp", "'end()' requested");
    runtimeState::end();
}