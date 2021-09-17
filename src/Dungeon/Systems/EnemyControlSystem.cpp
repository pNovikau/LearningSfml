#include "EnemyControlSystem.h"

#include "VectorMath.h"

#include "Helper.h"
#include "MoveComponent.h"
#include "EnemyStateChanged.h"
#include "EnemyStateComponent.h"

namespace dungeon::systems
{
    void EnemyControlSystem::update(const std::unique_ptr<engine::GameContext> &context)
    {
        const auto& entities = _entityManager->listEntitiesByComponent<components::EnemyStateComponent>();

        for (const auto& entity : entities)
        {
            const auto& stateComponent = entity->tryGetComponent<components::EnemyStateComponent>();

            if (stateComponent->nextStateTimeInSeconds >= context->time->getTime().asSeconds())
                continue;

            if (stateComponent->state == EnemyState::Idle)
            {
                const auto& moveComponent = entity->tryGetComponent<components::MoveComponent>();

                if (moveComponent != nullptr)
                {
                    events::EnemyStateChanged event;
                    event.entityId = entity->getId();
                    event.prevState = stateComponent->state;
                    event.currentState = EnemyState::Walking;

                    stateComponent->state = EnemyState::Walking;

                    moveComponent->direction = Utility::normalise({utils::Helper::randReal(-1.f, 1.f), utils::Helper::randReal(-1.f, 1.f)});

                    stateComponent->nextStateTimeInSeconds = context->time->getTime().asSeconds() + utils::Helper::randInt<int>(1, 3);

                    _eventManager->addEvent(event);
                }
            }
            else if (stateComponent->state == EnemyState::Walking)
            {
                const auto& moveComponent = entity->tryGetComponent<components::MoveComponent>();

                events::EnemyStateChanged event;
                event.entityId = entity->getId();
                event.prevState = stateComponent->state;
                event.currentState = EnemyState::Idle;

                stateComponent->state = EnemyState::Idle;

                moveComponent->direction.y = 0;
                moveComponent->direction.x = 0;

                stateComponent->nextStateTimeInSeconds = context->time->getTime().asSeconds() + utils::Helper::randInt<int>(1, 3);

                _eventManager->addEvent(event);
            }
        }
    }
}