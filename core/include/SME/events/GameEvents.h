#pragma once
#include <SFML/Graphics.hpp>

// Used for events and inputs
// Mouse input currently only supported
class GameEvents
{
protected:
    virtual ~GameEvents() = default;
    // Must be called every frame to gather new events
    virtual void updateEvents(sf::RenderWindow &target);
    // Used for when an event is needed
    [[nodiscard]] virtual bool getEvent(bool &windowOpen, sf::Event::EventType eventType) const;

    // Mouse input - Get current mouse position relative to window
    [[nodiscard]] virtual sf::Vector2f getMousePos(const sf::RenderWindow &target) { return {static_cast<float>(sf::Mouse::getPosition(target).x) , static_cast<float>(sf::Mouse::getPosition(target).y)}; }

private:
    // Engine holds updates that happened in the frame, not shared with main script
    sf::Event m_eventQueue = {};
    std::vector<sf::Event::EventType> m_currentEvents;
};

