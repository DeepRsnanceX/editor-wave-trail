#pragma once
#include <Geode/Bindings.hpp>
#include <Geode/Modify.hpp>

using namespace geode::prelude;

class TrailCutMod : public Mod {
public:
    static inline float trailCutFrequency = 0.5f; // Default frequency (0.5 skips every other frame)
    static inline bool toggleTrailCutting = true; // Toggle cutting effect

    void onLoad() override;
};
