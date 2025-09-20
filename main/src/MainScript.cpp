// Main code
#include "../include/MainScript.h"

Sprite* mySprite;
Text* myText;
Scene* myScene;

float velocity = 200.f;
float rotationSpeed = 90.f;
float sizeFactor = 0.9f;
void runtimeState::start(Application &app)
{
    myScene = sceneManager.createScene("main", 500);
    //app.setActiveScene(myScene);            // TODO: Make a log saying about if a scene is active or not. IF NOT abort render and mention error
    myText = myScene->createText("text", "Hello World!", {0, 0}, "assets/font/SegoeMarker.ttf", 60);
    myText->setObjectVisible(true);
    //myText->setOrigin({myText->getSize().x / 2, myText->getSize().y / 2});
    //myText->setOffset({myText->getSize().x / 2, myText->getSize().y / 2});
    //myText->setAngle(90);

    //mySprite = myScene->createSprite("player", "assets/textures/spaceship.png", myText->getPosition(), myText->getSize());
    //mySprite->setObjectVisible(true);

}

void runtimeState::update(Application &app, const float deltaTime)
{
    if (app.getEvent(sf::Event::KeyPressed))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            app.stopRunning();
        }
    }
}

void runtimeState::fixedUpdate(Application &app, const float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        myText->incrementPosition({-velocity * deltaTime, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        myText->incrementPosition({velocity * deltaTime, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        myText->incrementPosition({0, -velocity * deltaTime});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        myText->incrementPosition({0, velocity * deltaTime});
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
        myText->incrementAngle(-rotationSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        myText->incrementAngle(rotationSpeed * deltaTime);
    }

}

void runtimeState::end()
{
    delete mySprite;
    delete myText;
}