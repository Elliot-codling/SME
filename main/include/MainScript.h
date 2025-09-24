#pragma once
#include <sme/Sme.h>

#include "sme/assetMan/AssetManager.h"

namespace runtimeState
{
    void start(Application &app);
    void update(Application &app, float deltaTime);
    void fixedUpdate(Application &app, float deltaTime);
    void end();
}

inline SceneManager sceneManager;
inline AssetManager Resources;