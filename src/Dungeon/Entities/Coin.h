#pragma once

#include <string>

#include "Entity.h"

namespace dungeon::entities
{
    class Coin : public engine::Entity
    {
        using Entity::Entity;

    public:

        void init(const std::unique_ptr<engine::GameContext> &context) override;

    private:
        const std::string textureFrameKey = "coin_anim";
        const int frameCount = 4;
    };
}