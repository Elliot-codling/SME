#include "runtime.h"
#include "../include/mainScript.h"
Runtime::Runtime(const char* titleName, const int width, const int height)
{
    // Create the window and start the mainScript
    m_app.createWindow(titleName, width, height);
    // TODO: Create renderer
    runtimeState::start(m_app);
}

void Runtime::update()
{
    // Game loop
    while (m_app.isRunning())
    {
        m_timeElapsed = m_clock.restart();
        m_timeSinceLastUpdate += m_timeElapsed.asSeconds();

        //std::cout << m_timeElapsed.asMilliseconds() << std::endl;

        while (m_timeSinceLastUpdate >= c_fixedTime)
        {
            runtimeState::fixedUpdate(m_app, c_fixedTime);
            // Update current frametime
            //m_app.setFrametime(m_timeElapsed.asSeconds());
            m_timeSinceLastUpdate -= c_fixedTime;
        }
        runtimeState::update(m_app, m_timeElapsed.asSeconds());
    }
}

void Runtime::end()
{
    runtimeState::end();
}