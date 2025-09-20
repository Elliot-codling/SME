#include <sme/text/Text.h>

// ### Transforms ###
// --- Position ---
sf::Vector2f Text::getPosition() const
{
    const sf::Vector2f position = {m_text.getGlobalBounds().left, m_text.getGlobalBounds().top};
    LOG_TRACE("text/Text.cpp", std::format("'getPosition()' requested (ID={}) (pos={},{})", getId(), position.x, position.y));
    return position;
}

void Text::setPosition(const sf::Vector2f position)
{
    sf::Vector2f correctionOffset;
    // Calculate correction offset as text currently does not line up perfectly on the y axis
    correctionOffset.x = { m_text.getGlobalBounds().left - m_text.getPosition().x };
    correctionOffset.y = { m_text.getGlobalBounds().top - m_text.getPosition().y };
    // Apply correction offset and user level offset
    const sf::Vector2f newPosition = {
        (position.x - correctionOffset.x) + getOffset().x,
        (position.y - correctionOffset.y) + getOffset().y
    };

    LOG_TRACE("text/Text.cpp", std::format("'setPosition()' requested (ID={}) (pos_requested={},{}) (pos={},{})", getId(), position.x, position.y, newPosition.x, newPosition.y));
    m_text.setPosition(newPosition);
}

void Text::incrementPosition(const sf::Vector2f position)
{
    const sf::Vector2f newPosition = {m_text.getPosition().x + position.x, m_text.getPosition().y + position.y};
    LOG_TRACE("text/Text.cpp", std::format("'incrementPosition()' requested (ID={}) (pos={},{})", getId(), newPosition.x, newPosition.y));
    m_text.setPosition(newPosition);
}
void Text::setOrigin(const sf::Vector2f origin)
{
    LOG_TRACE("text/Text.cpp", std::format("'setOrigin()' requested (ID={}) (origin={},{})", getId(), origin.x, origin.y));
    m_text.setOrigin(origin.x, origin.y);
}
void Text::setOffset(const sf::Vector2f offset)
{
    LOG_TRACE("text/Text.cpp", std::format("'setOffset()' requested (ID={}) (offset={},{})", getId(), offset.x, offset.y));
    SharedData::setOffset(offset);
    incrementPosition(offset);
}





// --- Rotation ---
void Text::setAngle(const float angle)
{
    LOG_TRACE("text/Text.cpp", std::format("'setAngle()' requested (ID={}) (angle={})", getId(), angle));
    m_text.setRotation(angle);
}
void Text::incrementAngle(const float angle)
{
    LOG_TRACE("text/Text.cpp", std::format("'incrementAngle()' requested (ID={}) (angle={})", getId(), angle));
    m_text.rotate(angle);
}



// --- Scale ---
sf::Vector2f Text::getSize() const
{
    const sf::Vector2f size = {m_text.getGlobalBounds().width, m_text.getGlobalBounds().height};
    LOG_TRACE("text/Text.cpp", std::format("'getSize()' requested (ID={}) (size={},{})", getId(), size.x, size.y));
    return size;
}
void Text::setFontSize(const uint8_t fontSize)
{
    LOG_TRACE("text/Text.cpp", std::format("'setFontSize()' requested (ID={}) (size={})", getId(), fontSize));
    m_text.setCharacterSize(fontSize);
}