#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
    class DrawComponent : public Component<DrawComponent>
    {
    public:

        std::shared_ptr<sf::Drawable> drawable;
    };
}