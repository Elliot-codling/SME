#include <sme/sharedObjectClass/SharedObjectClass.h>


// ### Get functions ###
const char* SharedData::getId() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'getId()' requested");
    return m_id;
}
uint8_t SharedData::getLayerNumber() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'getLayerNumber()' requested");
    return m_layerNumber;
}
sf::Vector2f SharedData::getOffset() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'getOffset()' requested");
    return m_offset;
}
bool SharedData::isObjectVisible() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'isObjectVisible()' requested");
    return m_objectIsVisible;
}

// ### Set functions ###
void SharedData::setId(const char *objectID)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'setId()' requested");
    m_id = objectID;
}
void SharedData::setLayerNumber(const uint8_t objectLayer)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'setLayerNumber()' requested");
    m_layerNumber = objectLayer;
}
void SharedData::setObjectVisible(const bool isVisible)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'setObjectVisible()' requested");
    m_objectIsVisible = isVisible;
}
void SharedData::setOffset(const sf::Vector2f objectOffset)
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'setOffset()' requested");
    m_offset = objectOffset;
}

// ### Initialisation ###
bool SharedData::isInitialised() const
{
    LOG_TRACE("sharedObjectClass/SharedObjectClass.cpp", "'isInitialised()' requested");
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


