#pragma once
#include <SME/Sme.h>

namespace runtimeState
{
    void start(Application &app);
    void update(Application &app, float deltaTime);
    void fixedUpdate(Application &app, float deltaTime);
    void end();
}

inline SceneManager sceneManager;