#pragma once

#include "System.h"

namespace dungeon::systems
{
    class EnemyMoveSystem : public engine::System
    {
        void update(const std::unique_ptr<engine::GameContext> &context) override;
    };
}
