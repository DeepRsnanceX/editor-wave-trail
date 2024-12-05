#include "CheckpointManager.hpp"
#include <Geode/Modify.hpp>
#include <vector>

using namespace geode::prelude;

std::vector<CCSprite*> CheckpointManager::checkpoints;

void CheckpointManager::init() {
    checkpoints.clear();
}

void CheckpointManager::placeCheckpoint(CCPoint position) {
    auto sprite = CCSprite::create("checkpoint_icon.png"); // Use your icon texture
    sprite->setPosition(position);
    CCDirector::sharedDirector()->getRunningScene()->addChild(sprite);
    checkpoints.push_back(sprite);
}

void CheckpointManager::removeCheckpoint() {
    if (!checkpoints.empty()) {
        auto lastCheckpoint = checkpoints.back();
        lastCheckpoint->removeFromParent();
        checkpoints.pop_back();
    }
}

void CheckpointManager::clear() {
    for (auto checkpoint : checkpoints) {
        checkpoint->removeFromParent();
    }
    checkpoints.clear();
}

bool CheckpointManager::isNormalMode() {
    // Example of detecting if in normal mode. Adjust if necessary.
    return !GameManager::sharedState()->getPracticeMode();
}
