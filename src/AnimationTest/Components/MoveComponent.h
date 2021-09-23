#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

class MoveComponent : public engine::Component<MoveComponent>
{
public:
    bool canChangeDirection = true;
    float speed;
    sf::Vector2f direction;
};