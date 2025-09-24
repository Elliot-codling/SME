#include <sme/sprite/Sprite.h>

// ### Constructor ###
Sprite::Sprite(const char* objectId, sf::Texture* textureFile, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
    setId(objectId);
    LOG_TRACE("sprite/Sprite.cpp", std::format("Created 'Sprite' with ID={}", objectId));
    m_texture = textureFile;
    // Apply texture and position
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(position);

    setSize(size);
    setLayerNumber(objectLayer);

    // Once all passed have checked, the object has successfully initialised
    initialiseObject();
}
Sprite::~Sprite()
{
    LOG_TRACE("sprite/Sprite.cpp", std::format("Destroying object with ID={}", getId()));
    destroyObject();
}


// ### Debugging tools ###
void Sprite::setDebugActive(const sf::Color color)
{
    LOG_INFO("sprite/Sprite.cpp", std::format("'setDebugActive()' requested (ID={}) debug active", getId()));
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
