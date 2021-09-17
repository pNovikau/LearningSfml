#pragma once

#include "System.h"
#include "TransformComponent.h"

#include "Constants.h"

class PlayerTransformSystem : public engine::System
{
public:
    void update(const std::unique_ptr<engine::GameContext> &context) override
    {
        auto playerEntity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);
        auto moveComponent = playerEntity->tryGetComponent<MoveComponent>();
        auto transformComponent = playerEntity->tryGetComponent<engine::TransformComponent>();

        if (!moveComponent->canChangeDirection)
            return;

        transformComponent->velocity = moveComponent->direction;
    }
};