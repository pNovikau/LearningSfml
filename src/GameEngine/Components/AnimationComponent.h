#pragma once

#include "vector"
#include "memory"

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
    struct AnimationComponent : public Component<AnimationComponent>
    {
        bool isLooped = true;
        float timeDelay;
        float currentDelay;
        long offset;
        int currentFrame;
        int totalFrames;
        std::shared_ptr<sf::Sprite> sprite;
    };
}