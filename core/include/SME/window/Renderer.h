#pragma once
#include <SME/sprite/Sprite.h>
#include <SMe/scene/Scene.h>
class Renderer
{
public:
    virtual ~Renderer() = default;
protected:
    // Inherited by the GraceEngine class but not overwritten
    virtual void renderScene(sf::RenderWindow& target, sf::Color backgroundColor, Scene* scene);

    // Sorts the size_t list based on layer numbers
private:
    static std::vector<size_t>* sortSpriteQueue(const std::vector<Sprite>* spriteList, std::vector<size_t>* spriteRenderList);
};