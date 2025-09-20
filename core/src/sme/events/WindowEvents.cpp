#include <sme/events/WindowEvents.h>

// Clear current events
// Then gather new events happening in the window and store them to the queue
void WindowEvents::updateEvents(sf::RenderWindow &target)
{
    LOG_TRACE("events/WindowEvents.cpp", "'updateEvents()' requested");
    m_currentEvents.clear();
    while (target.pollEvent(m_eventQueue))
    {
        m_currentEvents.emplace_back(m_eventQueue.type);
    }
}

// Check through the current event list and check if any match the requested event type
// Close the window if the close button has been pressed
bool WindowEvents::getEvent(bool &windowOpen, const sf::Event::EventType eventType) const
{
    LOG_TRACE("events/WindowEvents.cpp", "'getEvent()' requested");
    for (auto &event : m_currentEvents)
    {
        if (event == sf::Event::Closed)
        {
            LOG_TRACE("events/WindowEvents.cpp", "Window closed event (bool=true)");
            windowOpen = false;
            return false;
        }
        if (event == eventType)
        {
            return true;
        }
    }
    return false;
}

sf::Vector2f WindowEvents::getMousePos(const sf::RenderWindow &target)
{
    const sf::Vector2f mousePos = {static_cast<float>(sf::Mouse::getPosition(target).x) , static_cast<float>(sf::Mouse::getPosition(target).y)};
    LOG_TRACE("events/WindowEvents.cpp", std::format("'getMousePos()' requested (pos={},{})", mousePos.x, mousePos.y));
    return mousePos;
}
