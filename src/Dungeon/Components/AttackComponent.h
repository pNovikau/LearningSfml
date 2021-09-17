#pragma once

#include <string>

#include "Component.h"

namespace dungeon::components
{
    struct AttackComponent : engine::Component<AttackComponent>
    {
        std::string targetEntity;
        float attackRadius;
    };
}