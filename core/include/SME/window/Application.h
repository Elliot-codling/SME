#pragma once
#include <SFML/Graphics.hpp>
#include <SME/events/GameEvents.h>
#include <SME/window/Renderer.h>

class Application : public GameEvents, Renderer
{
public:
    Application() = default;
    ~Application() override = default;

    // ### Lifetime ###
    void createWindow(const char* titleName, int width, int height);
    // --- Window state control ---
    [[nodiscard]] bool isRunning() const { return m_windowIsOpen; }
    void stopRunning() { m_windowIsOpen = false; }

    // ### Game Events ###
    void updateEvents() { GameEvents::updateEvents(m_window); }
    bool getEvent(const sf::Event::EventType eventType) { return GameEvents::getEvent(m_windowIsOpen, eventType); }
    // --- Mouse Control ---
    [[nodiscard]] sf::Vector2f getMousePos() { return GameEvents::getMousePos(m_window); }

    // ### Scene control ###
    void setActiveScene(Scene* scene)
    {
        m_activeScene = scene;
    }
    // ### Display control ###
    void setBackgroundColor(sf::Color backgroundColor) { m_backgroundColor = backgroundColor; }
    void updateDisplay();

private:
    // Variables
    sf::RenderWindow m_window;
    bool m_windowIsOpen;

    // Display settings
    sf::Color m_backgroundColor;

    // Store active scene, only the active scene will render
    Scene* m_activeScene = nullptr;
};
