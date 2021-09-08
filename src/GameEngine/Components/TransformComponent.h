#pragma once

#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <SFML/Graphics/Transformable.hpp>

namespace engine
{
    class TransformComponent : public Component
    {
    public:
        TransformComponent()
        {
            type = static_cast<int>(ComponentType::Transform);
        };

        std::shared_ptr<sf::Transformable> transformable;
        sf::Vector2f velocity{};
        float speed{};
    };
}