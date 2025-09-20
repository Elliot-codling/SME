#pragma once
#include <sme/sprite/Sprite.h>
#include <sme/scene/Scene.h>
#include <sme/log/logging.h>
class Renderer
{
public:
    Renderer() { LOG_TRACE("window/Renderer.h", "Creating 'Renderer'"); }
    virtual ~Renderer() { LOG_TRACE("window/Renderer.h", "Destroying 'Renderer'"); };
protected:
    // Inherited by the GraceEngine class but not overwritten
    virtual void renderScene(sf::RenderWindow& target, sf::Color backgroundColor, Scene* scene);

    // Sorts the size_t list based on layer numbers
private:
    static std::vector<size_t>* sortSpriteQueue(const std::vector<Sprite>* spriteList, std::vector<size_t>* spriteRenderList);
};