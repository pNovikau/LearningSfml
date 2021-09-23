#pragma once

#include <Constants.h>
#include "Components/TransformComponent.h"
#include "Events/CollisionEvent.h"
#include "Events/IEventHander.h"
#include "Systems/System.h"
#include "Utils/VectorMath.h"

namespace game
{
    class PlayerSystem :
            public engine::System,
            public engine::IEventHandler<engine::CollisionEvent>
    {
    public:
        void init(const std::unique_ptr<engine::GameContext> &context) override
        {
            subscribe<engine::CollisionEvent>();
        }

        void update(const std::unique_ptr<engine::GameContext> &context) override
        { }

        void handleEvent(const engine::CollisionEvent& event) override
        {
            if (event.currentEntityId != Constants::Entities::PLAYER_ID)
                return;

            const auto& currentEntity = _entityManager->getEntity<engine::Entity>(event.currentEntityId);
            const auto& targetEntity = _entityManager->getEntity<engine::Entity>(event.targetEntityId);

            const auto& currentTransformComponent = currentEntity->tryGetComponent<engine::TransformComponent>();
            const auto& targetTransformComponent = targetEntity->tryGetComponent<engine::TransformComponent>();

            const auto collisionNormal = targetTransformComponent->transformable->getPosition() - currentTransformComponent->transformable->getPosition();
            const auto manifold = Utility::getManifold(event.overlap, collisionNormal);
            sf::Vector2f normal(manifold.x, manifold.y);
            currentTransformComponent->transformable->move(normal * manifold.z);
        }

        template<typename TEvent>
        void subscribe()
        {
            _eventManager->subscribe<TEvent>([this]<typename TCollisionEvent>(TCollisionEvent && event)
            {
                handleEvent(std::forward<TCollisionEvent>(event));
            });
        }
    };
}