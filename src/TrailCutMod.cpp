#include "TrailCutMod.hpp"

// Hook into the trail rendering function
struct $modify(PlayerObject) {
    void update(float delta) {
        static float trailCutCounter = 0.0f;

        if (TrailCutMod::toggleTrailCutting) {
            // Increment counter by delta
            trailCutCounter += delta;

            // Skip rendering if counter exceeds frequency
            if (trailCutCounter >= TrailCutMod::trailCutFrequency) {
                trailCutCounter = 0.0f;
                return; // Simulate "cutting" by skipping rendering updates
            }
        }

        PlayerObject::update(delta); // Call the original function
    }
};

// Load the mod and register settings
void TrailCutMod::load() {
    // Add settings to the Geode settings menu
    Mod::get()->addCustomTab("Trail Cutting Settings", []() {
        auto menu = geode::createNode<MenuLayer>();
        
        // Add slider for trail cut frequency
        menu->addSlider(
            "Trail Cut Frequency",
            0.1f, 2.0f, trailCutFrequency,
            [](float value) { trailCutFrequency = value; }
        );

        // Add toggle for enabling/disabling the effect
        menu->addToggle(
            "Enable Trail Cutting",
            toggleTrailCutting,
            [](bool enabled) { toggleTrailCutting = enabled; }
        );

        return menu;
    });
}
