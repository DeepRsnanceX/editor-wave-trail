#include "HUDManager.hpp"
#include "CheckpointManager.hpp"
#include <Geode/Modify.hpp>

class $modify(GameObject) {
    void update(float dt) {
        GameObject::update(dt);

        if (CheckpointManager::isNormalMode()) {
            if (GetKeyState('Z') & 0x8000) { // 'Z' key
                auto player = GameManager::sharedState()->getPlayer();
                CheckpointManager::placeCheckpoint(player->getPosition());
            }
            if (GetKeyState('X') & 0x8000) { // 'X' key
                CheckpointManager::removeCheckpoint();
            }
        }
    }
};

class $modify(PlayerObject) {
    void playerDestroyed(bool idk) {
        PlayerObject::playerDestroyed(idk);

        if (CheckpointManager::isNormalMode()) {
            CheckpointManager::clear(); // Clear all checkpoints on death
        }
    }
};
