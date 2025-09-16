#include <sme/window/Application.h>

// ### Lifetime Control ###
bool Application::createWindow(const char *titleName, const int width, const int height)
{
    LOG_TRACE("Application.h", "'createWindow() requested'");
    m_window.create(sf::VideoMode(width, height, 32), titleName);
    // Check if window is able to open
    if (m_window.isOpen())
    {
        LOG_INFO("Application.h", "Successfully created SFML window: " + std::string(titleName));
        m_windowIsOpen = true;
        return true;
    }
    // Return false to stop program from running. Safe crash.
    LOG_FATAL("Application.h", "Cannot create window. Aborting.");
    m_windowIsOpen = false;
    return false;

}

bool Application::isRunning() const
{
    LOG_TRACE("Application.h", "'isRunning()' requested");
    return m_windowIsOpen;
}

void Application::stopRunning()
{
    LOG_TRACE("Application.h", "'stopRunning()' requested");
    m_windowIsOpen = false;
}

// ------------------------




// ### Game Events ###
void Application::updateEvents()
{
    LOG_TRACE("Application.h", "'updateEvents()' requested");
    GameEvents::updateEvents(m_window);
}

bool Application::getEvent(const sf::Event::EventType eventType)
{
    LOG_TRACE("Application.h", "'getEvent()' requested");
    return GameEvents::getEvent(m_windowIsOpen, eventType);
}

sf::Vector2f Application::getMousePos()
{
    LOG_TRACE("Application.h", "'getMousePos()' requested");
    return GameEvents::getMousePos(m_window);
}
// -------------------



// ### Scene control ###
void Application::setActiveScene(Scene *scene)
{
    LOG_TRACE("Application.h", "Created new scene: " + std::string(scene->getSceneName()));
    m_activeScene = scene;
}

// ### Display control ###
void Application::setBackgroundColor(const sf::Color backgroundColor)
{
    LOG_TRACE("Application.h", "'setBackgroundColor()' requested");
    m_backgroundColor = backgroundColor;
}

void Application::updateDisplay()
{
    Renderer::renderScene(m_window, m_backgroundColor, m_activeScene);
}
