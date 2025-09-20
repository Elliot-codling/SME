#include <sme/window/Renderer.h>

// Renders objects in the scene to the screen
void Renderer::renderScene(sf::RenderWindow& target, const sf::Color backgroundColor, Scene* scene)
{
    LOG_TRACE("window/Renderer.cpp", "'renderScene()' requested");
    target.clear(backgroundColor);

    // Create pointers to each queue
    const std::vector<Sprite>* spriteList = scene->getSpriteQueue();
    std::vector<Text>* textList = scene->getTextQueue();
    std::vector<size_t>* spriteRenderList = scene->getSpriteRenderQueue();

    sortSpriteQueue(spriteList, spriteRenderList);
    // Render objects in the m_spriteList based on the order from the spriteRenderList
    for (const size_t objectIndex: (*spriteRenderList))
    {
        (*spriteList)[objectIndex].render(target);
    }
    // TODO: Add performance tool monitor how long it took to render
    LOG_TRACE("window/Renderer.cpp", "Finished rendering sprites in: ");

    // Render text from the m_textList in order
    // No sorting for text
    for (Text &object : (*textList))
    {
        object.render(target);
    }
    LOG_TRACE("window/Renderer.cpp", "Finished rendering text in: ");
    LOG_TRACE("window/Renderer.cpp", "Updating display");
    target.display();
}

std::vector<size_t>* Renderer::sortSpriteQueue(const std::vector<Sprite>* spriteList, std::vector<size_t>* spriteRenderList)
{
    // TODO: Only sort the queue if an objects layer has changed (dirty)
    LOG_TRACE("window/Renderer.cpp", "'sortSpriteQueue()' requested'");
    if (!spriteList->empty())
    {
        LOG_TRACE("window/Renderer.cpp", "Starting sprite sort");
        // Sort the queue from the smallest layer number to the largest
        // Objects with the smallest layer number renders first
        // While the largest layer numbered objects renders last
        std::sort(spriteRenderList->begin(), spriteRenderList->end(),
        [spriteList](const size_t a, const size_t b) {
            return (*spriteList)[a].getLayerNumber() < (*spriteList)[b].getLayerNumber();
        });
        // TODO: Add performance logging as part of logging.h (or a separate file)
        LOG_TRACE("window/Renderer.cpp", "Finished sort in: ");
    }
    return spriteRenderList;
}
