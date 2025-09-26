#pragma once
#include <sme/sharedObjectClass/SharedObjectClass.h>
#include <sme/log/Logging.h>

class Text : public SharedData
{
public:
    // Constructor
    Text(const char* objectId, const char* message, sf::Vector2f position, sf::Font* fontFile, uint8_t fontSize);
    ~Text() override;

    // ### Transforms ###
    // --- Position ---
    // TODO: get position by getPosition() and another by getGlobalBounds()
    [[nodiscard]] sf::Vector2f getPosition() const;
    [[nodiscard]] sf::Vector2f getSize() const;

    void setPosition(sf::Vector2f position);
    void incrementPosition(sf::Vector2f position);

    // Offset and Origin functions
    void setOrigin(sf::Vector2f origin);
    void setOffset(sf::Vector2f offset) override;
    // --- Rotation ---

    void setAngle(float angle);
    void incrementAngle(float angle);

    // --- Scale ---
    void setFontSize(const uint8_t fontSize);


    // ### Text ###
    void updateString(const char* newMessage);

    // ### Render ###
    void render(sf::RenderTarget& target) const;

private:
    // Store font and text as ptr
    sf::Font* m_font;
    sf::Text m_text;
};
