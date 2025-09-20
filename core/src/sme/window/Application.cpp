#include <sme/window/Application.h>

// ### Lifetime Control ###
bool Application::createWindow(const char *titleName, const int width, const int height)
{
    LOG_TRACE("window/Application.cpp", "'createWindow()' requested");
    m_window.create(sf::VideoMode(width, height, 32), titleName);
    // Check if window is able to open
    if (m_window.isOpen())
    {
        LOG_INFO("window/Application.cpp", "Successfully created SFML window: " + std::string(titleName));
        m_windowIsOpen = true;
        return true;
    }
    // Return false to stop program from running. Safe crash.
    LOG_FATAL("window/Application.cpp", "Cannot create window. Aborting.");
    m_windowIsOpen = false;
    return false;

}

bool Application::isRunning() const
{
    LOG_TRACE("window/Application.cpp", std::format("'isRunning()' requested (bool={})", m_windowIsOpen));
    return m_windowIsOpen;
}

void Application::stopRunning()
{
    LOG_TRACE("window/Application.cpp", "'stopRunning()' requested");
    m_windowIsOpen = false;
}

// ------------------------




// ### Game Events ###
void Application::updateEvents()
{
    LOG_TRACE("window/Application.cpp", "'updateEvents()' requested");
    WindowEvents::updateEvents(m_window);
}

bool Application::getEvent(const sf::Event::EventType eventType)
{
    LOG_TRACE("window/Application.cpp", "'getEvent()' requested");
    return WindowEvents::getEvent(m_windowIsOpen, eventType);
}

sf::Vector2f Application::getMousePos()
{
    LOG_TRACE("window/Application.cpp", "'getMousePos()' requested");
    return WindowEvents::getMousePos(m_window);
}
// -------------------



// ### Scene control ###
Scene* Application::getActiveScene() const
{
    LOG_TRACE("window/Application.cpp", std::format("'getActiveScene()' requested (scene={})", m_activeScene ? m_activeScene->getSceneName() : "nullptr"));
    return m_activeScene;
}
void Application::setActiveScene(Scene* scene)
{
    LOG_TRACE("window/Application.cpp", std::format("'setActiveScene()' requested (scene={})", scene->getSceneName()));
    m_activeScene = scene;
}

// ### Display control ###
void Application::setBackgroundColor(const sf::Color backgroundColor)
{
    LOG_TRACE("window/Application.cpp", std::format("'setBackgroundColor()' requested (color=r:{},g:{},b:{},a:{})", backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a));
    m_backgroundColor = backgroundColor;
}
void Application::updateBlankDisplay()
{
    LOG_TRACE("window/Application.cpp", std::format("'updateBlankDisplay()' requested (scene={})", m_activeScene ? m_activeScene->getSceneName() : "nullptr"));
    Renderer::renderBlankScene(m_window, m_backgroundColor);
}
void Application::updateDisplay()
{
    LOG_TRACE("window/Application.cpp", std::format("'updateDisplay()' requested (scene={})", m_activeScene ? m_activeScene->getSceneName() : "nullptr"));
    Renderer::renderScene(m_window, m_backgroundColor, m_activeScene);
}
