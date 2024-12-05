#include <Geode/Geode.hpp>
#include "CheckpointManager.hpp"
#include "HUDManager.hpp"

using namespace geode::prelude;

class $mod(VisualCheckpoints) : public Mod {
public:
    void onEnable() override {
        CheckpointManager::init();
        HUDManager::init();
    }
    void onDisable() override {
        CheckpointManager::clear();
    }
};
