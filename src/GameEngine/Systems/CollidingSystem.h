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

                        // Player collision
                        /*if (currentEntity->getId() == game::Constants::Entities::PLAYER_ID)
                        {
                            if (targetEntity->getId() == game::Constants::Entities::BALL_ID)
                                continue;

                            auto collisionNormal = targetTransformComponent->transformable->getPosition() - currentTransformComponent->transformable->getPosition();
                            auto manifold = Utility::getManifold(overlap, collisionNormal);
                            sf::Vector2f normal(manifold.x, manifold.y);
                            currentTransformComponent->transformable->move(normal * manifold.z);

                            //TODO: move collision box
                        }
                            // Ball collision
                        else if (currentEntity->getId() == game::Constants::Entities::BALL_ID)
                        {
                            if (targetEntity->hasTag(game::Constants::Tags::TRIGGER))
                            {

                            }


                            auto collisionNormal = targetTransformComponent->transformable->getPosition() - currentTransformComponent->transformable->getPosition();
                            auto manifold = Utility::getManifold(overlap, collisionNormal);
                            sf::Vector2f normal(manifold.x, manifold.y);
                            currentTransformComponent->transformable->move(normal * manifold.z);

                            //TODO: move collision box

                            currentTransformComponent->velocity = Utility::reflect(currentTransformComponent->velocity, normal);
                        }*/
                    }
                }
            }
        }
    };
}

