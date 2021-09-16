#pragma once

#include "Components/CollidingComponent.h"
#include "Components/DrawComponent.h"
#include "Managers/EntityManager.h"
#include "System.h"

#include <utility>

namespace engine
{
    class DrawSystem : public System
    {
    public:
        DrawSystem(std::shared_ptr<EntityManager> entityManager, std::shared_ptr<EventManager> eventManager) : System(std::move(entityManager), std::move(eventManager))
        { }

        void update(const std::unique_ptr<GameContext>& context) override
        {
            _drawableEntities = _entityManager->listEntitiesByComponent<DrawComponent>();

            for (const auto& entity : _drawableEntities)
            {
                auto test = entity->tryGetComponent<DrawComponent>();
                context->window->draw(*test->drawable);

#ifndef NDEBUG
                const auto& collidingComponent = entity->tryGetComponent<CollidingComponent>();

                if (collidingComponent)
                    drawCollisionBox(context, collidingComponent);
#endif // !NDEBUG
            }
        }

    private:
        std::vector<std::shared_ptr<Entity>> _drawableEntities;

#ifndef NDEBUG
        static void drawCollisionBox(const std::unique_ptr<GameContext>& context, const std::shared_ptr<CollidingComponent>& component)
        {
            const auto& bounding_box = component->globalBounds;

            auto collision_box = sf::RectangleShape({ bounding_box.width, bounding_box.height });
            collision_box.setPosition(bounding_box.left, bounding_box.top);
            collision_box.setOutlineColor(sf::Color::Red);
            collision_box.setFillColor(sf::Color::Transparent);
            collision_box.setOutlineThickness(1);

            context->window->draw(collision_box);
        }
#endif // !NDEBUG
    };
}