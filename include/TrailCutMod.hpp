#pragma once
#include <Geode/Bindings.hpp>
#include <Geode/Modify.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class TrailCutMod {
public:
    static inline float trailCutFrequency = 0.5f; // Default frequency (0.5 skips every other frame)
    static inline bool toggleTrailCutting = true; // Toggle cutting effect

    static void load(); // Called during mod loading
};
