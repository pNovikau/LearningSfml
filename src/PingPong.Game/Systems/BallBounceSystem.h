#pragma once

#include <Systems/System.h>
#include <Events/IEventHander.h>
#include <Events/CollisionEvent.h>
#include "Utils/VectorMath.h"

namespace game
{
	class BallBounceSystem :
		public engine::System,
		public engine::IEventHandler<engine::CollisionEvent>
	{
	public:
		explicit BallBounceSystem(std::shared_ptr<engine::EntityManager> entityManager, std::shared_ptr<engine::EventManager> eventManager) : System(std::move(entityManager), std::move(eventManager))
		{}

		void init(const std::unique_ptr<engine::GameContext>& context) override
		{
			subscribe<engine::CollisionEvent>();
		}

		void update(const std::unique_ptr<engine::GameContext>& context) override
		{ }

		void handleEvent(const engine::CollisionEvent& event) override
        {
            if (event.currentEntityId != Constants::Entities::BALL_ID)
                return;

            const auto& currentEntity = _entityManager->getEntity<engine::Entity>(event.currentEntityId);
            const auto& targetEntity = _entityManager->getEntity<engine::Entity>(event.targetEntityId);

            const auto& currentTransformComponent = currentEntity->tryGetComponent<engine::TransformComponent>();
            const auto& targetTransformComponent = targetEntity->tryGetComponent<engine::TransformComponent>();

            const auto collisionNormal = targetTransformComponent->transformable->getPosition() - currentTransformComponent->transformable->getPosition();
            const auto manifold = Utility::getManifold(event.overlap, collisionNormal);
            const sf::Vector2f normal(manifold.x, manifold.y);
            currentTransformComponent->transformable->move(normal * manifold.z);

            currentTransformComponent->velocity = Utility::reflect(currentTransformComponent->velocity, normal);
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