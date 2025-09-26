#include <sme/sharedObjectClass/SharedObjectClass.h>

// ### Get functions ###
const char* SharedData::getId() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'getId()' requested (ID={})", m_id));
    return m_id;
}
uint8_t SharedData::getLayerNumber() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'getLayerNumber()' requested (int={})", m_layerNumber));
    return m_layerNumber;
}
sf::Vector2f SharedData::getOffset() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'getOffset()' requested (pos={},{})", m_offset.x, m_offset.y));
    return m_offset;
}
bool SharedData::isObjectVisible() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'isObjectVisible()' requested (bool={})", m_objectIsVisible));
    return m_objectIsVisible;
}

// ### Set functions ###
void SharedData::setId(const char *objectID)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'setId()' requested (ID={})", objectID));
    m_id = objectID;
}
void SharedData::setLayerNumber(const uint8_t objectLayer)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'setLayerNumber()' requested (int={})", objectLayer));
    m_layerNumber = objectLayer;
}
void SharedData::setObjectVisible(const bool isVisible)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'setObjectVisible()' requested (bool={})", isVisible));
    m_objectIsVisible = isVisible;
}
void SharedData::setOffset(const sf::Vector2f objectOffset)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'setOffset()' requested (pos={},{})", objectOffset.x, objectOffset.y));
    m_offset = objectOffset;
}

// ### Initialisation ###
bool SharedData::isInitialised() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", std::format("'isInitialised()' requested (bool={})", m_initialised));
    return m_initialised;
}

// Protected
void SharedData::initialiseObject()
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'initialiseObject()' requested");
    m_initialised = true;
}
void SharedData::destroyObject()
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'destroyObject()' requested");
    m_initialised = false;
}
