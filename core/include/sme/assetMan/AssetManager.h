#pragma once
#include <SFML/Graphics.hpp>
#include <sme/log/Logging.h>
#include <unordered_map>

class AssetManager
{
public:
    AssetManager() { LOG_TRACE("assetMan/AssetManager.h", std::format("Creating 'AssetManager'")); }
    ~AssetManager();

    // ### Textures ###
    sf::Texture* loadTexture(const char* textureDir);

    // ### Font ###
    sf::Font* loadFont(const char* fontDir);

private:
    // ### Variables ###
    std::unordered_map<const char*, sf::Texture> m_texturePool;
    std::unordered_map<const char*, sf::Font> m_fontPool;

    // ### Functions ##
    sf::Texture* findCachedTexture(const char* uniqueKey);
    sf::Font* findCachedFont(const char* uniqueKey);

};
