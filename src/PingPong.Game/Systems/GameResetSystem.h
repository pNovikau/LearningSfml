#pragma once

#include <Constants.h>
#include <Ball.h>
#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Components/TriggerComponent.h"
#include "Events/TriggerEvent.h"
#include "Systems/System.h"

namespace game
{
    class GameResetSystem : public engine::System
    {
    public:
        explicit GameResetSystem(std::shared_ptr<engine::EntityManager> entityManager, std::shared_ptr<engine::EventManager> eventManager) : System(std::move(entityManager), std::move(eventManager)) {}

        void init(const std::unique_ptr<engine::GameContext>& context) override
        {
            subscribe<TriggerEvent>();
        }

        void update(const std::unique_ptr<engine::GameContext> &context) override
        { }

        void handleEvent(const TriggerEvent& event)
        {
            if (event.targetEntityId != Constants::Entities::BALL_ID)
                return;

            const auto& ballEntity = _entityManager->getEntity<Ball>(Constants::Entities::BALL_ID);
            const auto& ballTransformComponent = ballEntity->tryGetComponent<engine::TransformComponent>();

            ballTransformComponent->transformable->setPosition(ballEntity->defaultPosition);
            ballTransformComponent->velocity = Utility::normalise({ -0.5f, 0.1f });
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