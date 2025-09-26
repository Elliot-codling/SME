// Main code
#include "../include/MainScript.h"

#include <cmath>

#include "sme/log/Profiler.h"

Sprite* mySprite;
Text* myText;
Scene* myScene;

float velocity = 200.f;
float rotationSpeed = 90.f;
float sizeFactor = 0.9f;
void runtimeState::start(Application &app)
{
    myScene = sceneManager.createScene("main", 500);
    app.setActiveScene(myScene);
    myText = myScene->createText("text", "Hello World!", {0, 0}, Resources.loadFont("assets/font/SegoeMarker.ttf"), 60);
    myText->setObjectVisible(true);

    mySprite = myScene->createSprite("player", Resources.loadTexture("assets/textures/spaceship.png"), {10, 10}, {64, 64});
    mySprite->setObjectVisible(true);
}

void runtimeState::update(Application &app, const float deltaTime)
{
    if (app.getEvent(sf::Event::KeyPressed))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            app.stopRunning();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            double number;
            START_WATCH();
            for (int i = 0; i<10000000; i++)
            {
                number = 1 / sqrt(i);
            }
            STOP_WATCH("main/MainScript.cpp");
        }
    }
}

void runtimeState::fixedUpdate(Application &app, const float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mySprite->incrementPosition({-velocity * deltaTime, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mySprite->incrementPosition({velocity * deltaTime, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mySprite->incrementPosition({0, -velocity * deltaTime});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mySprite->incrementPosition({0, velocity * deltaTime});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        mySprite->setSize(mySprite->getSize() * sizeFactor);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        mySprite->setSize(mySprite->getSize() * (2 - sizeFactor));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        mySprite->incrementAngle(-rotationSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mySprite->incrementAngle(rotationSpeed * deltaTime);
    }

}

void runtimeState::end()
{
    //delete mySprite;
    //delete myText;
}