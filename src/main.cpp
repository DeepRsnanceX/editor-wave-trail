#include <Geode/Geode.hpp>
#include <Geode/modify/HardStreak.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify (HardStreak)
{
    void updateStroke(float p0)
    {
        if (auto lel = LevelEditorLayer::get())
            m_drawStreak = true;

        HardStreak::updateStroke(p0);
    }

};

class $modify (PlayerObject)
{
    void placeStreakPoint()
    {
        if (LevelEditorLayer::get() && m_isDart)
            m_waveTrail->addPoint(this->getPosition());
        else
            PlayerObject::placeStreakPoint();
    }

    virtual void update(float dt)
    {
        PlayerObject::update(dt);

        if (LevelEditorLayer::get() && m_isDart)
            m_waveTrail->m_currentPoint = this->getPosition();
    }

    void fadeOutStreak2(float p0)
    {
        PlayerObject::fadeOutStreak2(p0);

        if (LevelEditorLayer::get())
            m_waveTrail->runAction(CCFadeTo::create(p0, 0));
    }

};
