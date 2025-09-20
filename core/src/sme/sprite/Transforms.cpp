#include <sme/sprite/Sprite.h>

// ### Transforms ###
// -- Position ---
sf::Vector2f Sprite::getPosition() const
{
    const sf::Vector2f position = {m_sprite.getPosition() - getOffset()};
    LOG_TRACE("sprite/Transforms.cpp", std::format("'getPosition()' requested (ID={}) (pos={},{})", getId(), position.x, position.y));
    return position;
}
sf::Vector2f Sprite::getGlobalPosition() const
{
    const sf::Vector2f position = {m_sprite.getGlobalBounds().left, m_sprite.getGlobalBounds().top};
    LOG_TRACE("sprite/Transforms.cpp", std::format("'getGlobalPosition()' requested (ID={}) (pos={},{})", getId(), position.x, position.y));
    return position;
}
void Sprite::setPosition(const sf::Vector2f position)
{
    const sf::Vector2f newPosition = {position.x + getOffset().x, position.y + getOffset().y};
    LOG_TRACE("sprite/Transforms.cpp", std::format("'setPosition()' requested (ID={}) (pos_requested={},{}) (pos_returned={},{})", getId(), position.x, position.y, newPosition.x, newPosition.y));
    m_sprite.setPosition(newPosition);
}
void Sprite::incrementPosition(const sf::Vector2f position)
{
    const sf::Vector2f newPosition = {m_sprite.getPosition().x + position.x, m_sprite.getPosition().y + position.y};
    LOG_TRACE("sprite/Transforms.cpp", std::format("'incrementPosition()' requested (ID={}) (pos_requested={},{}) (pos_returned={},{})", getId(), position.x, position.y, newPosition.x, newPosition.y));
    m_sprite.setPosition(newPosition);
}
// Offset values and origin values
// Define object offset value
void Sprite::setOffset(const sf::Vector2f objectOffset)
{
    LOG_TRACE("sprite/Transforms.cpp", std::format("'setOffset()' requested (ID={}) (offset={},{})", getId(), objectOffset.x, objectOffset.y));
    SharedData::setOffset(objectOffset);		// Define the offset value
    incrementPosition(objectOffset);		// Move the object
}
// Set the Origin point of the sprite
void Sprite::setOrigin(const sf::Vector2f origin)
{
    const sf::Vector2f newOrigin = {origin.x / m_sprite.getScale().x, origin.y / m_sprite.getScale().y};
    LOG_TRACE("sprite/Transforms.cpp", std::format("'setOrigin()' requested (ID={}) (origin_requested={},{}) (origin_returned={},{})", getId(), origin.x, origin.y, newOrigin.x, newOrigin.y));
    m_sprite.setOrigin(newOrigin);
}



// --- Rotation ---
float Sprite::getAngle() const
{
    const float angle = m_sprite.getRotation();
    LOG_TRACE("sprite/Transforms.cpp", std::format("'getAngle()' requested (ID={}) (angle={})", getId(), angle));
    return angle;
}
void Sprite::setAngle(const float angle)
{
    LOG_TRACE("sprite/Transforms.cpp", std::format("'setAngle()' requested (ID={}) (angle={})", getId(), angle));
    m_sprite.setRotation(angle);
}
void Sprite::incrementAngle(const float angle)
{
    LOG_TRACE("sprite/Transforms.cpp", std::format("'incrementAngle()' requested (ID={}) (angle={})", getId(), angle));
    m_sprite.rotate(angle);
}



// --- Scale ---
sf::Vector2f Sprite::getSize() const
{
    const sf::Vector2f size = {
        static_cast<float>(m_texture->getSize().x) * m_sprite.getScale().x,
        static_cast<float>(m_texture->getSize().y) * m_sprite.getScale().y
    };
    LOG_TRACE("sprite/Transforms.cpp", std::format("'getSize()' requested (ID={}) (size={},{})", getId(), size.x, size.y));
    return size;
}
sf::Vector2f Sprite::getGlobalSize() const
{
    const sf::Vector2f size = {m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height};
    LOG_TRACE("sprite/Transforms.cpp", std::format("'getGlobalSize()' requested (ID={}) (size={},{})", getId(), size.x, size.y));
    return size;
}
void Sprite::setSize(const sf::Vector2f size)
{
    if (!m_texture->isRepeated())
    {
        const sf::Vector2f scale = {size.x / static_cast<float>(m_texture->getSize().x), size.y / static_cast<float>(m_texture->getSize().y)};
        LOG_TRACE("sprite/Transforms.cpp", std::format("'setSize()' requested (ID={}) (size={},{}) (scale={},{}) (texture_repeated=false)", getId(), size.x, size.y, scale.x, scale.y));
        m_sprite.setScale(scale);
    }
    else
    {
        LOG_TRACE("sprite/Transforms.cpp", std::format("'setSize()' requested (ID={}) (size={},{}) (texture_repeated=true)", getId(), size.x, size.y));
        m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
    }
}