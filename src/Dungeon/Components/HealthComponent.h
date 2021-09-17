#pragma once

#include "Component.h"

namespace dungeon::components
{
    struct HealthComponent : engine::Component<HealthComponent>
    {
        int health;
    };
}