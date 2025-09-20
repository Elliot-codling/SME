#include <sme/sprite/Sprite.h>

// This file is used to calculate the collision between the current object and the targeted object

// ### Collision ###
// Virtual border checks
bool Sprite::leftBorder(const sf::Vector2i relativePosition, const int borderLeft) const
{
    const bool hitBorder = relativePosition.x >= borderLeft;
    LOG_TRACE("sprite/Collision.cpp", std::format("'leftBorder()' requested (ID={}) (bool={})", getId(), hitBorder));
    return hitBorder;
}
bool Sprite::rightBorder(const sf::Vector2i relativePosition, const int borderRight) const
{
    const bool hitBorder = relativePosition.x <= borderRight;
    LOG_TRACE("sprite/Collision.cpp", std::format("'rightBorder()' requested (ID={}) (bool={})", getId(), hitBorder));
    return hitBorder;
}
bool Sprite::topBorder(const sf::Vector2i relativePosition, const int borderTop) const
{
    const bool hitBorder = relativePosition.y >= borderTop;
    LOG_TRACE("sprite/Collision.cpp", std::format("'topBorder()' requested (ID={}) (bool={})", getId(), hitBorder));
    return hitBorder;
}
bool Sprite::bottomBorder(const sf::Vector2i relativePosition, const int borderBottom) const
{
    const bool hitBorder = relativePosition.y <= borderBottom;
    LOG_TRACE("sprite/Collision.cpp", std::format("'bottomBorder()' requested (ID={}) (bool={})", getId(), hitBorder));
    return hitBorder;
}


// Return an object ID if the selected sprite has collided with the object
std::string Sprite::collisionBox(const Sprite* object) const
{
    LOG_TRACE("sprite/Collision.cpp", std::format("'collisionBox()' requested (ID={}) checking for collision...", getId()));
    if (!(getPosition().x <= object->getPosition().x + object->getSize().x))
    {
        return "";
    }
    if (!(getPosition().x + getSize().x >= object->getPosition().x))
    {
        return "";
    }
    if (!(getPosition().y <= object->getPosition().y + object->getSize().y))
    {
        return "";
    }
    if (!(getPosition().y + getSize().y >= object->getPosition().y))
    {
        return "";
    }

    const char* objectID = object->getId();
    LOG_TRACE("sprite/Collision.cpp", std::format("Collision detected with {}", objectID));
    return objectID;
}