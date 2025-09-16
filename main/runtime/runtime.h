#pragma once
#include <sme/Sme.h>
#include <iostream>
class Runtime
{
public:
    Runtime(const char* titleName, int width, int height);
    ~Runtime() = default;

    void update();
    void end();

private:
    // Variables
    Application m_app;

    // For fixed update, runs at 60fps (16.666ms)
    const float c_fixedTime = 1.f / 60.f;

    float m_timeSinceLastUpdate = 0.f;
    float m_deltaTime = 0.f;
    sf::Clock m_clock;
    sf::Time m_timeElapsed;

};
