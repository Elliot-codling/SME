#pragma once
#include <SFML/Graphics.hpp>
#include <sme/log/logging.h>

// Used for events and inputs
// Mouse input currently only supported
class WindowEvents
{
protected:
    WindowEvents() { LOG_TRACE("events/WindowEvents.h", "Creating 'WindowEvents'"); }
    virtual ~WindowEvents() { LOG_TRACE("events/WindowEvents.h", "Destroying 'WindowEvents'"); }

    // ### Window Events
    // Gather new events in each frame
    virtual void updateEvents(sf::RenderWindow &target);
    // Check if a specified event has occurred
    [[nodiscard]] virtual bool getEvent(bool &windowOpen, sf::Event::EventType eventType) const;

    // ### Mouse Control ###
    [[nodiscard]] virtual sf::Vector2f getMousePos(const sf::RenderWindow &target);

private:
    // Engine holds updates that happened in the frame
    sf::Event m_eventQueue = {};
    std::vector<sf::Event::EventType> m_currentEvents;
};

