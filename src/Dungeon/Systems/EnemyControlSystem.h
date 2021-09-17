#pragma once

#include "System.h"

namespace dungeon::systems
{
    class EnemyControlSystem : public engine::System
    {
        //void init(const std::unique_ptr<engine::GameContext>& context) override;
        void update(const std::unique_ptr<engine::GameContext> &context) override;
    };
}
