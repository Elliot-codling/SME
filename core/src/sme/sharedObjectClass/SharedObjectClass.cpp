#include <sme/sharedObjectClass/SharedObjectClass.h>

// ### Get functions ###
const char* SharedData::getId() const
{
    return m_id;
}
uint8_t SharedData::getLayerNumber() const
{
    return m_layerNumber;
}
sf::Vector2f SharedData::getOffset() const
{
    return m_offset;
}
bool SharedData::isObjectVisible() const
{
    return m_objectIsVisible;
}

// ### Set functions ###
void SharedData::setId(const char *objectID)
{
    m_id = objectID;
}
void SharedData::setLayerNumber(const uint8_t objectLayer)
{
    m_layerNumber = objectLayer;
}
void SharedData::setObjectVisible(const bool isVisible)
{
    m_objectIsVisible = isVisible;
}
void SharedData::setOffset(const sf::Vector2f objectOffset)
{
    m_offset = objectOffset;
}

// ### Initialisation ###
bool SharedData::isInitialised() const
{
    return m_initialised;
}

// Protected
void SharedData::initialiseObject()
{
    m_initialised = true;
}
void SharedData::destroyObject()
{
    m_initialised = false;
}


