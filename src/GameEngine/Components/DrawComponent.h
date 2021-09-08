#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
    class DrawComponent : public Component
    {
    public:
        DrawComponent()
        {
            type = static_cast<int>(ComponentType::Draw);
        }

        std::shared_ptr<sf::Drawable> drawable;
    };
}