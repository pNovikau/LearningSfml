#pragma once

#include "Entity.h"

namespace dungeon::entities
{   
    class BigDemon : public engine::Entity
    {
        using Entity::Entity;

    public:

        void init(const std::unique_ptr<engine::GameContext> &context) override;

    private:
        const std::string runTextureKey = "big_demon_run_anim";
        const int runTextureFrames = 4;

        const std::string idleTextureKey = "big_demon_idle_anim";
        const int idleTextureFrames = 4;
    };
}