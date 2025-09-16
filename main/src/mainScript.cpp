// Main code
#include "../include/mainScript.h"


Scene* myScene;

void runtimeState::start(Application &app)
{
    myScene = sceneManager.createScene("main", 500);
    Text* myText = myScene->createText("text", "Hello World!", {10, 10}, "assets/font/SegoeMarker.ttf", 30);
    myText->setObjectVisible(true);
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

}

void runtimeState::end()
{

}