#pragma once
#include <SFML/Graphics.hpp>

#include <sme/log/Logging.h>
#include <fmt/format.h>
// Sprite and Text objects will share some functions
// This class will be inherited between them
// Nodiscard -> warn users if a get function is called but not used in program

class SharedData
{
public:
    virtual ~SharedData() = default;

    // ### Get functions ###
    [[nodiscard]] const char* getId() const;
    [[nodiscard]] uint8_t getLayerNumber() const;
    [[nodiscard]] sf::Vector2f getOffset() const;
    [[nodiscard]] bool isObjectVisible() const;

    // ### Set functions ###
    void setId(const char* objectID);
    void setLayerNumber(uint8_t objectLayer);
    void setObjectVisible(bool isVisible);
    virtual void setOffset(sf::Vector2f objectOffset);

    // ### Initialisation ###
    [[nodiscard]] bool isInitialised() const;

protected:
    void initialiseObject();
    void destroyObject();

private:
    // Inherited variables
    uint8_t m_layerNumber = 0;
    const char* m_id = new char;
    sf::Vector2f m_offset;

    // Is the object initialised?
    bool m_initialised = false;
    // Determines if the object is going to rendered to the screen
    bool m_objectIsVisible = false;

};