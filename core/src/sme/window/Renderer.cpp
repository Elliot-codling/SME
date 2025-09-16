#include <sme/window/Renderer.h>
#include <iostream>

#include "sme/log/logging.h"

// Renders objects in the scene to the screen
void Renderer::renderScene(sf::RenderWindow& target, const sf::Color backgroundColor, Scene* scene)
{
    LOG_TRACE("Renderer.cpp", "'renderScene()' requested");
    target.clear(backgroundColor);

    // Create pointers to each queue
    const std::vector<Sprite>* spriteList = scene->getSpriteQueue();
    LOG_TRACE("Renderer.cpp", "Gathered spriteList, current size: " + std::to_string(spriteList->size()));
    std::vector<Text>* textList = scene->getTextQueue();
    LOG_TRACE("Renderer.cpp", "Gathered textList, current size: " + std::to_string(textList->size()));
    std::vector<size_t>* spriteRenderList = scene->getSpriteRenderList();
    LOG_TRACE("Renderer.cpp", "Gathered spriteRenderList, current size: " + std::to_string(spriteRenderList->size()));

    sortSpriteQueue(spriteList, spriteRenderList);
    // Render objects in the m_spriteList based on the order from the spriteRenderList
    LOG_TRACE("Renderer.cpp", "Starting render for items in spriteList. Number of items: " + std::to_string(spriteList->size()));
    for (const size_t objectIndex: (*spriteRenderList))
    {
        (*spriteList)[objectIndex].render(target);
    }

    // Render text from the m_textList in order
    // No sorting for text
    LOG_TRACE("Renderer.cpp", "Starting render for items in textList. Number of items: " + std::to_string(textList->size()));
    for (Text &object : (*textList))
    {
        object.render(target);
    }
    LOG_TRACE("Renderer.cpp", "Updating display");
    target.display();
}

std::vector<size_t>* Renderer::sortSpriteQueue(const std::vector<Sprite>* spriteList, std::vector<size_t>* spriteRenderList)
{
    // TODO: Only sort the queue if an objects layer has changed (dirty)
    LOG_TRACE("Renderer.cpp", "'sortSpriteQueue()' requested'");
    if (!spriteList->empty())
    {
        LOG_TRACE("Renderer.cpp", "Starting sprite sort");
        // Sort the queue from the smallest layer number to the largest
        // Objects with the smallest layer number renders first
        // While the largest layer numbered objects renders last
        std::sort(spriteRenderList->begin(), spriteRenderList->end(),
        [spriteList](const size_t a, const size_t b) {
            return (*spriteList)[a].getLayerNumber() < (*spriteList)[b].getLayerNumber();
        });
        // TODO: Add performance logging as part of logging.h (or a separate file)
        LOG_TRACE("Renderer.cpp", "Finished sort in: ");
    }
    return spriteRenderList;
}
