#include "TrailCutMod.hpp"

// Hook into the trail rendering function (example: PlayerObject::update or similar)
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

// Add a settings menu for customization
void TrailCutMod::onLoad() {
    Mod::get()->addHook("PlayerObject", &PlayerObject::update);

    // Add settings
    Mod::get()->addMenu(
        "Trail Cutting Settings",
        []() {
            auto menu = MenuLayer::create();
            menu->addSlider(
                "Trail Cut Frequency",
                0.1f, 2.0f, trailCutFrequency,
                [](float value) { trailCutFrequency = value; }
            );
            menu->addToggle(
                "Enable Trail Cutting",
                toggleTrailCutting,
                [](bool enabled) { toggleTrailCutting = enabled; }
            );
            return menu;
        }
    );
}
