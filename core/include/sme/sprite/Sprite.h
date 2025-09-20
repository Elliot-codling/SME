#pragma once
#include <SFML/Graphics.hpp>
#include <sme/SharedObjectClass.h>
#include <sme/log/logging.h>

class Sprite : public SharedData
{
public:
    Sprite(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer);
    Sprite(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
    ~Sprite() override;

    // ### Transforms ###
    // -- Position ---
    [[nodiscard]] sf::Vector2f getPosition() const;;		// <-- Not affected by rotation
    [[nodiscard]] sf::Vector2f getGlobalPosition() const;

    void setPosition(sf::Vector2f position);
    void incrementPosition(sf::Vector2f position);

    // Offset values and origin values
    void setOffset(sf::Vector2f objectOffset) override;
    void setOrigin(sf::Vector2f origin);

    // --- Rotation ---
    [[nodiscard]] float getAngle() const;
    void setAngle(float angle);
    void incrementAngle(float angle);

    // --- Scale ---
    [[nodiscard]] sf::Vector2f getSize() const; // <-- Not affected by rotation
    [[nodiscard]] sf::Vector2f getGlobalSize() const;
    void setSize(sf::Vector2f size);

    // ### Collision ###
    // Virtual border checks
    [[nodiscard]] bool leftBorder(sf::Vector2i relativePosition, int borderLeft) const;
    [[nodiscard]] bool rightBorder(sf::Vector2i relativePosition, int borderRight) const;
    [[nodiscard]] bool topBorder(sf::Vector2i relativePosition, int borderTop) const;
    [[nodiscard]] bool bottomBorder(sf::Vector2i relativePosition, int borderBottom) const;

    // Simple AABB collision
    std::string collisionBox(const Sprite* object) const;
    // ### Debugging tools ###
    void setDebugActive(sf::Color color = { 255, 255, 255 });


    // ### Render ###
    void render(sf::RenderTarget &target) const;

private:
    // Variables
    // TODO: Make a texture script which will load in a texture IF it hasnt done so already
    sf::Texture* m_texture = new sf::Texture;
    sf::Sprite m_sprite;

    sf::RectangleShape* m_debugRect = nullptr;
    bool m_spriteIsDebugging = false;
};
