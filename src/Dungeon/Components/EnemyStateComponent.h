#pragma once

#include "EnemyState.h"
#include "Component.h"

namespace dungeon::components
{
    struct EnemyStateComponent : engine::Component<EnemyStateComponent>
    {
        EnemyState state;
        size_t nextStateTimeInSeconds = 0;
    };
}