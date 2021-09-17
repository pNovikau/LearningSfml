#pragma once

#include "SFML/Graphics.hpp"

#include "Component.h"

namespace dungeon::components
{
    struct MoveComponent : engine::Component<MoveComponent>
    {
        float speed;
        sf::Vector2f direction;
    };
}