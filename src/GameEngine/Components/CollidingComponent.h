#pragma once

#include <SFML/Graphics/Rect.hpp>
#include "memory"
#include "Component.h"

namespace engine
{
    class CollidingComponent : public Component
    {
    public:
        CollidingComponent()
        {
            type = static_cast<int>(ComponentType::Collision);
        }

        sf::FloatRect globalBounds;
        sf::FloatRect localBounds;
    };
}