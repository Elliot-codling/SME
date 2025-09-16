#include <SME/sprite/Sprite.h>

// ### Constructor ###
Sprite::Sprite(const char *objectId, const char *textureDir, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
    setId(objectId);

    // Load the texture from the dir provided
    if (!m_texture->loadFromFile(textureDir))
    {
        // TODO: Add log message here
        return;
    }

    // Apply texture and position
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(position);

    setSize(size);
    setLayerNumber(objectLayer);

    // Once all passed have checked, the object has successfully initialised
    initialiseObject();
}

Sprite::Sprite(const char* objectId, const sf::Texture& textureFile, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
    setId(objectId);

    // Apply texture and position
    m_sprite.setTexture(textureFile);
    m_sprite.setPosition(position);

    setSize(size);
    setLayerNumber(objectLayer);

    // Once all passed have checked, the object has successfully initialised
    initialiseObject();
}

// ### Debugging tools ###
void Sprite::setDebugActive(const sf::Color color)
{
    m_debugRect = new sf::RectangleShape;
    m_debugRect->setSize(getSize());
    m_debugRect->setFillColor(color);
    m_debugRect->setPosition(getPosition());
    m_spriteIsDebugging = true;
}

// ### Render ###
void Sprite::render(sf::RenderTarget &target) const
{
    if (!isObjectVisible())
    {
        return;
    }
    if (m_spriteIsDebugging)
    {
        m_debugRect->setSize(getSize());
        m_debugRect->setRotation(m_sprite.getRotation());
        m_debugRect->setPosition(getPosition() + getOffset());
        // 7.5 * (64/15)
        m_debugRect->setOrigin(m_sprite.getOrigin().x * m_sprite.getScale().x, m_sprite.getOrigin().y * m_sprite.getScale().y);
        target.draw(*m_debugRect);
    }
    target.draw(m_sprite);
}
