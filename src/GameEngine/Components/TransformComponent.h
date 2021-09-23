#pragma once

#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "Component.h"

namespace engine
{
    class TransformComponent : public Component<TransformComponent>
    {
    public:

        std::shared_ptr<sf::Transformable> transformable;
        sf::Vector2f velocity;
        float speed;
    };
}