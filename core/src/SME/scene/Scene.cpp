#include <iostream>
#include <SME/scene/Scene.h>

// ### Constructor ###
Scene::Scene(const char* sceneName, const uint32_t vectorSize)
{
    // Set name and vector size
    m_sceneName = sceneName;
    m_spriteList.reserve(vectorSize);
    m_spriteRenderList.reserve(vectorSize);
}

// ### Creation ###
// --- Sprite ---

/* Steps:
 * 1. Create a pointer to a SpriteObject.
 * 2. Check if we have met the capacity of the list, if we have then print a warning and return the temporary sprite.
 * 3. Else, add sprite to queue as well as the index.
 * 4. Return the memory location of the new sprite.
 */
Sprite* Scene::createSprite(const char* objectId, const char *textureDir, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
    auto* newSprite = new Sprite(objectId, textureDir, position, size, objectLayer);
    if (m_spriteList.size() >= m_spriteList.capacity()) {
        //printWarningInfo("Could not add new sprite, size has exceeded capacity.");
        // TODO: Add log
        std::cerr << "Could not add new sprite.\n";
        return newSprite;
    }

    m_spriteList.emplace_back(*newSprite);
    m_spriteRenderList.emplace_back(m_spriteList.size() - 1);
    return &m_spriteList.back();
}

Sprite* Scene::createSprite(const char* objectId, const sf::Texture &textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer)
{
    auto* newSprite = new Sprite(objectId, textureFile, position, size, objectLayer);
    if (m_spriteList.size() >= m_spriteList.capacity()) {
        //printWarningInfo("Could not add new sprite, size has exceeded capacity.");
        // TODO: Add log
        std::cerr << "Could not add new sprite.\n";
        return newSprite;
    }

    m_spriteList.emplace_back(*newSprite);
    m_spriteRenderList.emplace_back(m_spriteList.size() - 1);
    return &m_spriteList.back();
}

// --- Text ---

/* Steps:
 * 1. Create a pointer to a new TextObject.
 * 2. Add to the vector.
 * 3. Return the memory location of the TextObject.
 */

Text* Scene::createText(const char* objectId, const char* message, const sf::Vector2f position, const char* fontDir, const uint8_t fontSize) {
    m_textList.emplace_back(objectId, message, position, fontDir, fontSize);
    Text* textLocation = &m_textList.back();
    return textLocation;
}

Text* Scene::createText(const char* objectId, const char* message, const sf::Vector2f position, const sf::Font &fontFile, const uint8_t fontSize) {
    m_textList.emplace_back(objectId, message, position, fontFile, fontSize);
    return &m_textList.back();
}



void Scene::clearLayer(const uint16_t layerNumber)
{
    // TODO: Needs to be completed
}