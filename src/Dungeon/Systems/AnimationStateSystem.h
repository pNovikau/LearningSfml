#pragma once

#include "System.h"

#include "EnemyStateChanged.h"

namespace dungeon::systems
{
    class AnimationStateSystem : public engine::System
    {
        void init(const std::unique_ptr<engine::GameContext>& context) override;
        void update(const std::unique_ptr<engine::GameContext> &context) override;

        void handleEvent(const events::EnemyStateChanged& event);

    private:
        template<typename TEvent>
        void subscribe()
        {
            _eventManager->subscribe<TEvent>([this]<typename TCollisionEvent>(TCollisionEvent && event)
            {
                handleEvent(std::forward<TCollisionEvent>(event));
            });
        }
    };
}
