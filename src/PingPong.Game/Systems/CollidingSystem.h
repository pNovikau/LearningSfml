#pragma once

#include <Constants.h>
#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Systems/System.h"
#include "Utils/VectorMath.h"

namespace game
{
    class CollidingSystem : public engine::System
    {
    public:
        CollidingSystem(std::shared_ptr<engine::EntityManager> entityManager) : System(std::move(entityManager)) {};

        void update(const std::unique_ptr<engine::GameContext> &context) override
        {
            const auto& entities = _entityManager->listEntitiesByComponents<engine::CollidingComponent, engine::TransformComponent>();

            for (const auto& currentEntity : entities)
            {
                const auto& currentCollidingComponent = currentEntity->addOrGetComponent<engine::CollidingComponent>();
                const auto& currentTransformComponent = currentEntity->addOrGetComponent<engine::TransformComponent>();

                for (const auto& entity : entities)
                {
                    if (currentEntity->getId() == entity->getId())
                        continue;

                    const auto& collidingComponent = entity->addOrGetComponent<engine::CollidingComponent>();
                    const auto& transformComponent = entity->addOrGetComponent<engine::TransformComponent>();
                    sf::FloatRect overlap;

                    if (currentCollidingComponent->globalBounds.intersects(collidingComponent->globalBounds, overlap))
                    {
                        if (currentEntity->getId() == game::Constants::Entities::PLAYER_ID)
                        {
                            if (entity->getId() == game::Constants::Entities::BALL_ID)
                                continue;

                            //TODO: player collision
                            auto collisionNormal = transformComponent->transformable->getPosition() - currentTransformComponent->transformable->getPosition();
                            auto manifold = Utility::getManifold(overlap, collisionNormal);
                            sf::Vector2f normal(manifold.x, manifold.y);
                            currentTransformComponent->transformable->move(normal * manifold.z);

                        }
                        else if (currentEntity->getId() == game::Constants::Entities::BALL_ID)
                        {
                            //TODO: ball collision
                            auto collisionNormal = transformComponent->transformable->getPosition() - currentTransformComponent->transformable->getPosition();
                            auto manifold = Utility::getManifold(overlap, collisionNormal);
                            sf::Vector2f normal(manifold.x, manifold.y);
                            currentTransformComponent->transformable->move(normal * manifold.z);

                            currentTransformComponent->velocity = Utility::reflect(currentTransformComponent->velocity, normal);
                        }
                    }
                }
            }
        }
    };
}