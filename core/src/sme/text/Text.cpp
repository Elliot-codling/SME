#include <sme/text/Text.h>

// Text constructor ------------------------------------------------------------------------------
Text::Text(const char* objectId, const char* message, const sf::Vector2f position, const char* fontDir, const uint8_t fontSize)
{
    setId(objectId);
    if (!m_font->loadFromFile(fontDir))
    {
        // TODO: Add log
        return;
    }

    // Set the string and font
    m_text.setFont(*m_font);
    m_text.setCharacterSize(fontSize);
    m_text.setString(message);

    setPosition(position);
    setLayerNumber(0);

    // Once all passed have checked, the object has successfully initialised
    initialiseObject();
}

Text::Text(const char* objectId, const char* message, const sf::Vector2f position, const sf::Font& fontFile, const uint8_t fontSize)
{
    setId(objectId);
    *m_font = fontFile;

    m_text.setFont(*m_font);
    m_text.setCharacterSize(fontSize);
    m_text.setString(message);

    setPosition(position);
    setLayerNumber(0);

    // Once all passed have checked, the object has successfully initialised
    initialiseObject();
}

Text::~Text()
{
    //De-initialise object
    destroyObject();
    delete m_font;
}

void Text::setPosition(const sf::Vector2f position)
{
    sf::Vector2f offSet;
    offSet.x = { m_text.getGlobalBounds().left - m_text.getPosition().x };
    offSet.y = { m_text.getGlobalBounds().top - m_text.getPosition().y };

    m_text.setPosition({ position.x - offSet.x, position.y - offSet.y });
}

void Text::setOrigin(const sf::Vector2f origin)
{
    m_text.setOrigin(origin.x, origin.y);
}

void Text::render(sf::RenderTarget& target) const
{
    if (!isObjectVisible())
    {
        return;
    }
    target.draw(m_text);
}

