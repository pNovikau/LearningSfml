#pragma once

#include "Entity.h"

namespace dungeon::entities
{
    class Floor : public engine::Entity
    {
        using Entity::Entity;

    public:
        void init(const std::unique_ptr<engine::GameContext> &context) override;

        void setPosition(sf::FloatRect position) { _position = position; }
    private:
        const std::string floorTextureKey = "floor_1";

        sf::FloatRect _position;
    };
}