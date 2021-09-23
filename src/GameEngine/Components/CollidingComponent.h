#pragma once

#include <SFML/Graphics/Rect.hpp>
#include "Component.h"

namespace engine
{
    class CollidingComponent : public Component<CollidingComponent>
    {
    public:

        sf::FloatRect globalBounds;
        sf::FloatRect localBounds;
    };
}