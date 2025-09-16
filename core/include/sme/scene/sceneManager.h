#pragma once
#include <sme/scene/Scene.h>
class SceneManager
{
public:
    SceneManager() = default;
    ~SceneManager() = default;

    // ### Lifetime controls ###
    Scene* createScene(const char* sceneName, uint32_t vectorSize);
    void deleteScene(const char* sceneName);

    // ### Loading and unloading ###
    Scene* loadScene(const char* sceneName);
    void unloadScene(const char* sceneName);

private:
    uint8_t m_numberOfActiveScenes = 0;
    uint8_t m_maxNumberOfActiveScenes = 1;

    Scene* m_activeScene = nullptr;
};