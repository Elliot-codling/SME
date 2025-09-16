#include <SME/scene/sceneManager.h>
Scene* SceneManager::createScene(const char* sceneName, const uint32_t vectorSize)
{
    // EXPERIMENTAL
    // TODO: Must get the vector size based on engine properties configurable by the user
    m_activeScene = new Scene(sceneName, vectorSize);
    return m_activeScene;
}

void SceneManager::deleteScene(const char* sceneName)
{

}

Scene* SceneManager::loadScene(const char* sceneName)
{
    return nullptr;
}

void SceneManager::unloadScene(const char* sceneName)
{

}
