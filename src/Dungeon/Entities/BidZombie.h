#pragma once

#include "Entity.h"

namespace dungeon::entities
{
    class BidZombie : public engine::Entity
    {
        using Entity::Entity;

    public:

        void init(const std::unique_ptr<engine::GameContext> &context) override;

    private:
        const std::string runTextureKey = "big_zombie_run_anim";
        const int runTextureFrames = 4;

        const std::string idleTextureKey = "big_zombie_idle_anim";
        const int idleTextureFrames = 4;
    };
}