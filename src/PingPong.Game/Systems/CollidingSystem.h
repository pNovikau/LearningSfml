#pragma once

#include <Constants.h>
#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Systems/System.h"

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

                    const auto& collidingComponent = currentEntity->addOrGetComponent<engine::CollidingComponent>();
                    sf::FloatRect overlap;

                    if (currentCollidingComponent->collidingBody->intersects(*collidingComponent->collidingBody, overlap))
                    {
                        if (currentEntity->getId() == game::Constants::Entities::PLAYER_ID)
                        {
                            if (entity->getId() == game::Constants::Entities::BALL_ID)
                                continue;

                            //TODO: player collision
                        }
                        else if (currentEntity->getId() == game::Constants::Entities::BALL_ID)
                        {
                            //TODO: ball collision
                        }
                    }
                }
            }
        }
    };
}