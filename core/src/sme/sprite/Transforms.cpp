#include <sme/sprite/Sprite.h>

// ### Transforms ###
// -- Position ---
// Define object offset value
void Sprite::setOffset(const sf::Vector2f objectOffset)
{
    SharedData::setOffset(objectOffset);		// Define the offset value
    incrementPosition(objectOffset);		// Move the object
}

// Set the Origin point of the sprite
void Sprite::setOrigin(const sf::Vector2f origin)
{
    m_sprite.setOrigin(origin.x / m_sprite.getScale().x, origin.y / m_sprite.getScale().y);
}


// --- Scale ---
void Sprite::setSize(const sf::Vector2f size)
{
    if (!m_texture->isRepeated())
    {
        m_sprite.setScale(size.x / static_cast<float>(m_texture->getSize().x), size.y / static_cast<float>(m_texture->getSize().y));
    }
    else
    {
        m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
    }
}

