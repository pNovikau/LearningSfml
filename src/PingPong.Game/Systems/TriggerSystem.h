#pragma once

#include <Constants.h>
#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Components/TriggerComponent.h"
#include "Events/TriggerEvent.h"
#include "Systems/System.h"

namespace game
{
    class TriggerSystem : public engine::System
    {
    public:
        void update(const std::unique_ptr<engine::GameContext> &context) override
        {
            const auto& entities = _entityManager->listEntitiesByComponents<engine::CollidingComponent, engine::TransformComponent>();
            const auto& triggers = _entityManager->listEntitiesByComponent<TriggerComponent>();

            for (const auto& triggerEntity : triggers)
            {
                const auto& triggerComponent = triggerEntity->tryGetComponent<TriggerComponent>();

                for (const auto& entity : entities)
                {
                    const auto& entityCollidingComponent = entity->tryGetComponent<engine::CollidingComponent>();

                    if (triggerComponent->body.intersects(entityCollidingComponent->globalBounds))
                    {
                        TriggerEvent event;
                        event.targetEntityId = entity->getId();
                        event.triggerEntityId = triggerEntity->getId();

                        _eventManager->addEvent<TriggerEvent>(event);
                    }
                }

#ifndef NDEBUG
                const auto& bounding_box = triggerComponent->body;

                auto collision_box = sf::RectangleShape({ bounding_box.width, bounding_box.height });
                collision_box.setPosition(bounding_box.left, bounding_box.top);
                collision_box.setOutlineColor(sf::Color::Yellow);
                collision_box.setFillColor(sf::Color::Transparent);
                collision_box.setOutlineThickness(1);

                context->window->draw(collision_box);
#endif //!NDEBUG
            }
        }
    };
}