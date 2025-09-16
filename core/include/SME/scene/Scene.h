#pragma once
#include <Sme/sprite/Sprite.h>
#include <Sme/text/text.h>
class Scene
{
public:
    Scene(const char* sceneName, uint32_t vectorSize);
    ~Scene() = default;

    // ### Creation ###
    // --- Sprite ---
    [[nodiscard]] Sprite* createSprite(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
    [[nodiscard]] Sprite* createSprite(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
    // --- Text ---
    [[nodiscard]] Text* createText(const char* objectId, const char* message, sf::Vector2f position, const char* fontDir, uint8_t fontSize);
    [[nodiscard]] Text* createText(const char* objectId, const char* message, sf::Vector2f position, const sf::Font& fontFile, uint8_t fontSize);

    // Return vectors
    [[nodiscard]] std::vector<Sprite>* getSpriteQueue() { return &m_spriteList; }
    [[nodiscard]] std::vector<Text>* getTextQueue() { return &m_textList; }
    [[nodiscard]] std::vector<size_t>* getSpriteRenderList() { return &m_spriteRenderList; }

    // Layers
    void clearLayer(uint16_t layerNumber);

private:
    const char* m_sceneName;
    // Vector to hold the sprite objects
    std::vector<Sprite> m_spriteList;
    // Vector of indexes of each sprite. This can be sorted so that the correct order of sprites are rendered
    std::vector<size_t> m_spriteRenderList;
    // Vector to hold the text objects
    std::vector<Text> m_textList;
};

