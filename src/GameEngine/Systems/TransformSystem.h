#pragma once

#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Managers/EntityManager.h"
#include "System.h"

namespace engine
{
    class TransformSystem : public System
    {
    public:
        void update(const std::unique_ptr<GameContext>& context) override
        {
            _transformableEntities = _entityManager->listEntitiesByComponent<TransformComponent>();

            for (const auto& entity : _transformableEntities)
            {
                const auto component = entity->tryGetComponent<TransformComponent>();

                if (component->velocity.x != 0 || component->velocity.y != 0)
                {
                    component->transformable->move(component->velocity * component->speed * context->time->getDelta().asSeconds());

                    const auto& collidingComponent = entity->tryGetComponent<CollidingComponent>();

                    if (collidingComponent)
                    {
                        auto globalBounds = component->transformable->getTransform().transformRect(collidingComponent->localBounds);

                        collidingComponent->globalBounds = globalBounds;
                    }
                }
            }
        }

    private:
        std::vector<std::shared_ptr<Entity>> _transformableEntities;
    };
}