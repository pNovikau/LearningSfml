#pragma once

#include "vector"
#include "memory"

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
    struct AnimationComponent : public Component<AnimationComponent>
    {
        std::vector<std::shared_ptr<sf::Sprite>> sprites;
        float timeDelay;
    };
}