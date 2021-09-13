#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "Components/Component.h"
#include "Constants.h"

namespace game
{
    class TriggerComponent : public engine::Component
    {
    public:
        TriggerComponent()
        {
            type = Constants::Components::TRIGGER;
        }

        sf::FloatRect body;
    };
}