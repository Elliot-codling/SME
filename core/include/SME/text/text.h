#pragma once
#include <SME/SharedObjectClass.h>

class Text : public SharedData
{
public:
    // Constructor
    Text(const char* objectId, const char* message, sf::Vector2f position, const char* fontDir, uint8_t fontSize);
    Text(const char* objectId, const char* message, sf::Vector2f position, const sf::Font& fontFile, uint8_t fontSize);
    ~Text() override;

    // ### Transforms ###
    // --- Position ---
    [[nodiscard]] sf::Vector2f getPosition() const { return { m_text.getGlobalBounds().left, m_text.getGlobalBounds().top }; }
    [[nodiscard]] sf::Vector2f getSize() const { return { m_text.getLocalBounds().width, m_text.getLocalBounds().height }; }

    void setPosition(sf::Vector2f position);
    void incrementPosition(const sf::Vector2f position) { m_text.setPosition(m_text.getPosition().x + position.x, m_text.getPosition().y + position.y); }
    // --- Rotation ---
    void setOrigin(sf::Vector2f origin);
    void setAngle(const float angle) { m_text.setRotation(angle); }
    void incrementAngle(const float angle) { m_text.rotate(angle); }
    // --- Scale ---
    void setFontSize(const uint8_t fontSize) { m_text.setCharacterSize(fontSize); }


    // ### Text ###
    void updateString(const char* newMessage) { m_text.setString(newMessage); }

    // ### Render ###
    void render(sf::RenderTarget& target) const;

private:
    // Store font and text as ptr
    sf::Font* m_font = new sf::Font;
    sf::Text m_text;
};
