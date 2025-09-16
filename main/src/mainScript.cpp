// Main code
#include "../include/mainScript.h"

Sprite* mySprite;
Scene* myScene;

float velocity = 200.f;
float rotationSpeed = 90.f;
float sizeFactor = 0.9f;
void runtimeState::start(Application &app)
{
    myScene = sceneManager.createScene("main", 500);
    app.setActiveScene(myScene);            // TODO: Make a log saying about if a scene is active or not. IF NOT abort render and mention error
    Text* myText = myScene->createText("text", "Hello World!", {10, 10}, "assets/font/SegoeMarker.ttf", 30);
    myText->setObjectVisible(true);

    mySprite = myScene->createSprite("player", "assets/textures/spaceship.png", {10, 10}, {64, 64});
    mySprite->setObjectVisible(true);
    mySprite->setOrigin({32, 32});
    mySprite->setOffset({32, 32});

    //Logger::setMinLogLevel(LogLevel::Debug);

    LOG_TRACE("mainScript.cpp", "Hello World!");
    LOG_DEBUG("mainScript.cpp", "Hello World!");
    LOG_INFO("mainScript.cpp", "Hello World!");
    LOG_WARN("mainScript.cpp", "Hello World!");
    LOG_ERROR("mainScript.cpp", "Hello World!");
    LOG_FATAL("mainScript.cpp", "Hello World!");


}

void runtimeState::update(Application &app, const float deltaTime)
{
    app.updateEvents();
    if (app.getEvent(sf::Event::KeyPressed))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            app.stopRunning();
        }
    }

    app.updateDisplay();
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

}