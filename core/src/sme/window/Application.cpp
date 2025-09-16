#include <sme/window/Application.h>

// ### Lifetime ###
void Application::createWindow(const char *titleName, int width, int height)
{
    m_window.create(sf::VideoMode(width, height, 32), titleName);
    if (m_window.isOpen())
    {
        m_windowIsOpen = true;
    }
    else
    {
        m_windowIsOpen = false;
    }
}


// ### Display control ###
void Application::updateDisplay()
{
    Renderer::renderScene(m_window, m_backgroundColor, m_activeScene);
}
