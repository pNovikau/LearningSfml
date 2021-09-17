#pragma once

#include <string>

#include "Event.h"

#include "EnemyStateComponent.h"

namespace dungeon::events
{
    struct EnemyStateChanged : engine::Event<EnemyStateChanged>
    {
        std::string entityId;
        EnemyState currentState;
        EnemyState prevState;
    };
}