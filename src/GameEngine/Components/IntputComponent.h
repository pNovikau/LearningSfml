#pragma once

#include "vector"

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace engine
{
    class InputComponent : public Component<InputComponent>
    {
    public:

        std::vector<sf::Keyboard::Key> keysFilter;
    };
}