#pragma once
#include <Geode/Geode.hpp>
#include <vector>

class CheckpointManager {
public:
    static void init();
    static void placeCheckpoint(cocos2d::CCPoint position);
    static void removeCheckpoint();
    static void clear();
    static bool isNormalMode();

private:
    static std::vector<cocos2d::CCSprite*> checkpoints;
};
