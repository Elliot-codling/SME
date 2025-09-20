#include <sme/text/Text.h>

// Text constructor ------------------------------------------------------------------------------
Text::Text(const char* objectId, const char* message, const sf::Vector2f position, const char* fontDir, const uint8_t fontSize)
{
    setId(objectId);
    LOG_TRACE("text/Text.cpp", std::format("Created 'Text' with ID={}", objectId));
    if (!m_font->loadFromFile(fontDir))
    {
        // TODO: To be replaced by asset manager
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
    LOG_TRACE("text/Text.cpp", std::format("Created 'Text' with ID={}", objectId));
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
    LOG_TRACE("text/Text.cpp", std::format("Destroying object with ID={}", getId()));
    //De-initialise object
    destroyObject();
    delete m_font;
}

// ### Text ###
void Text::updateString(const char *newMessage)
{
    LOG_TRACE("text/Text.cpp", std::format("'updateString()' requested (ID={}) (message={})", getId(), newMessage));
    m_text.setString(newMessage);
}

// ### Render ###
void Text::render(sf::RenderTarget& target) const
{
    LOG_TRACE("text/Text.cpp", std::format("'render()' requested (ID={})", getId()));
    if (!isObjectVisible())
    {
        return;
    }
    target.draw(m_text);
}

