#include "EnemyMoveSystem.h"

#include "TransformComponent.h"

#include "MoveComponent.h"
#include "EnemyStateComponent.h"

namespace dungeon::systems
{

    void EnemyMoveSystem::update(const std::unique_ptr<engine::GameContext> &context)
    {
        const auto& entities = _entityManager->listEntitiesByComponents<
                components::EnemyStateComponent,
                components::MoveComponent,
                engine::TransformComponent>();

        for (const auto& entity : entities)
        {
            const auto& moveComponent = entity->tryGetComponent<components::MoveComponent>();
            //const auto& stateComponent = entity->tryGetComponent<components::EnemyStateComponent>();
            const auto& transformComponent = entity->tryGetComponent<engine::TransformComponent>();

            transformComponent->velocity = moveComponent->direction;
        }
    }
}