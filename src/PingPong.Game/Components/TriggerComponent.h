#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "Components/Component.h"
#include "Constants.h"

namespace game
{
    class TriggerComponent : public engine::Component<TriggerComponent>
    {
    public:

        sf::FloatRect body;
    };
}