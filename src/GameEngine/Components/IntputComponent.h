#pragma once

#include "vector"

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
    class InputComponent : public Component
    {
    public:
        InputComponent()
        {
            type = static_cast<int>(ComponentType::Input);
        }

        std::vector<sf::Keyboard::Key> keysFilter{};
    };
}