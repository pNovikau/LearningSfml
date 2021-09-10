#pragma once

#include "Systems/System.h"
#include "Events/CollisionEvent.h"
#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Utils/VectorMath.h"

namespace engine
{
    class CollidingSystem : public System
    {
    public:
        explicit CollidingSystem(std::shared_ptr<EntityManager> entityManager, std::shared_ptr<EventManager> eventManager) : System(std::move(entityManager), std::move(eventManager))
        {}

        void update(const std::unique_ptr<GameContext> &context) override
        {
            const auto& entities = _entityManager->listEntitiesByComponents<CollidingComponent, TransformComponent>();

            for (const auto& currentEntity : entities)
            {
                const auto& currentCollidingComponent = currentEntity->addOrGetComponent<CollidingComponent>();

                for (const auto& targetEntity : entities)
                {
                    if (currentEntity->getId() == targetEntity->getId())
                        continue;

                    const auto& targetCollidingComponent = targetEntity->addOrGetComponent<CollidingComponent>();
                    sf::FloatRect overlap;

                    if (currentCollidingComponent->globalBounds.intersects(targetCollidingComponent->globalBounds, overlap))
                    {
                        CollisionEvent event;
                        event.overlap = overlap;
                        event.targetEntityId = targetEntity->getId();
                        event.currentEntityId = currentEntity->getId();

                        _eventManager->addEvent<CollisionEvent>(event);

                        //TODO: add collision logic
                    }
                }
            }
        }
    };
}

