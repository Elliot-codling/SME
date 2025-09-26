#include <sme/assetMan/AssetManager.h>


AssetManager::~AssetManager()
{
    LOG_TRACE("assetMan/AssetManager.cpp", fmt::format("Destroying 'AssetManager'"));
}

// ### Textures ###
sf::Texture* AssetManager::loadTexture(const char* textureDir)
{
    LOG_TRACE("assetMan/AssetManager.cpp", "'loadTexture()' requested");
    if (sf::Texture* cachedTexture = findCachedTexture(textureDir); cachedTexture != nullptr)
    {
        return cachedTexture;
    }

    // Load a new texture as requested, texture is not present in m_texturePool
    sf::Texture texture;
    if (texture.loadFromFile(textureDir))
    {
        // Found file, return texture and store in m_texturePool
        LOG_INFO("assetMan/AssetManager.cpp", fmt::format("Loaded texture from directory=({})", textureDir));

        m_texturePool.emplace(textureDir, std::move(texture));
        return &(m_texturePool.at(textureDir));
    }

    // Find external texture file as user file could not be found, check cache first
    LOG_WARN("assetMan/AssetManager.cpp", fmt::format("Could not find texture with directory=({}) using placeholder texture", textureDir));

    const char* externalTextureDir = "external/textures/FileNotFound.png";
    if (sf::Texture* cachedTexture = findCachedTexture(externalTextureDir); cachedTexture != nullptr)
    {
        return cachedTexture;
    }

    if (texture.loadFromFile(externalTextureDir))
    {
        // Found external file, return texture and store in m_texturePool
        m_texturePool.emplace(textureDir, std::move(texture));
        return &(m_texturePool.at(textureDir));
    }

    // Could not locate any files, error and return empty pointer of sf::Texture
    LOG_ERROR("assetMan/AssetManager.cpp", fmt::format("Could not find external texture in directory=({}), returning blank texture", externalTextureDir));
    return new sf::Texture;

}
// ### Font ###
sf::Font* AssetManager::loadFont(const char* fontDir)
{
    LOG_TRACE("assetMan/AssetManager.cpp", "'loadFont()' requested");
    // Check if the font can be found and return a pointer to the memory location
    if (sf::Font* cachedFont = findCachedFont(fontDir); cachedFont != nullptr)
    {
        return cachedFont;
    }

    // Load a new font as requested, font is not present in m_fontPool
    sf::Font font;
    if (font.loadFromFile(fontDir))
    {
        // Found file, return font and store in m_fontPool
        LOG_INFO("assetMan/AssetManager.cpp", fmt::format("Loaded font from directory=({})", fontDir));

        m_fontPool.emplace(fontDir, std::move(font));
        return &(m_fontPool.at(fontDir));
    }

    // Find external font file as user file could not be found, check cache first
    LOG_WARN("assetMan/AssetManager.cpp", fmt::format("Could not find font with directory=({}) using placeholder font", fontDir));

    const char* externalFontDir = "external/font/OpenSans-Regular.ttf";
    if (sf::Font* cachedFont = findCachedFont(externalFontDir); cachedFont != nullptr)
    {
        return cachedFont;
    }

    if (font.loadFromFile(externalFontDir))
    {
        // Found external file, return font and store in m_fontPool
        m_fontPool.emplace(fontDir, std::move(font));
        return &(m_fontPool.at(fontDir));
    }

    // Could not locate any files, error and return empty nullptr
    LOG_ERROR("assetMan/AssetManager.cpp", fmt::format("Could not find external font in directory=({}), returning nullptr", externalFontDir));
    return nullptr;
}




// ### Private functions ###
sf::Texture* AssetManager::findCachedTexture(const char* uniqueKey)
{
    LOG_TRACE("assetMan/AssetManager.cpp", "'findCachedTexture()' requested");
    // Check if the texture can be found and return a pointer to the memory location
    if (const auto it = m_texturePool.find(uniqueKey); it != m_texturePool.end())
    {
        LOG_INFO("assetMan/AssetManager.cpp", fmt::format("Found cached texture with directory=({})", uniqueKey));
        return &(it->second);
    }
    return nullptr;
}

sf::Font* AssetManager::findCachedFont(const char* uniqueKey)
{
    LOG_TRACE("assetMan/AssetManager.cpp", "'findCachedFont()' requested");
    // Check if the texture can be found and return a pointer to the memory location
    if (const auto it = m_fontPool.find(uniqueKey); it != m_fontPool.end())
    {
        LOG_INFO("assetMan/AssetManager.cpp", fmt::format("Found cached font with directory=({})", uniqueKey));
        return &(it->second);
    }
    return nullptr;
}
