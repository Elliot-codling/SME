#pragma once
#include <SFML/Graphics.hpp>
#include <sme/events/GameEvents.h>
#include <sme/window/Renderer.h>

#include "sme/log/logging.h"

class Application : public GameEvents, Renderer
{
public:
    Application() = default;
    ~Application() override = default;

    // ### Lifetime Control ###
    bool createWindow(const char* titleName, int width, int height);
    // --- Window state control ---
    [[nodiscard]] bool isRunning() const;
    void stopRunning();

    // ### Game Events ###
    void updateEvents();
    bool getEvent(const sf::Event::EventType eventType);
    // --- Mouse Control ---
    [[nodiscard]] sf::Vector2f getMousePos();

    // ### Scene control ###
    void setActiveScene(Scene* scene);
    // ### Display control ###
    void setBackgroundColor(sf::Color backgroundColor);
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
