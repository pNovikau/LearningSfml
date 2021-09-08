#pragma once

#include "Systems/System.h"
#include "Managers/EntityManager.h"
#include "Components/TransformComponent.h"
#include "Components/IntputComponent.h"

namespace game
{
    class InputSystem : public engine::System
    {
    public:
        InputSystem(std::shared_ptr<engine::EntityManager> entityManager) : System(std::move(entityManager)) {}

        void update(const std::unique_ptr<engine::GameContext> &context) override
        {
            auto entities = _entityManager->listEntitiesByComponents<engine::TransformComponent, engine::InputComponent>();

            for (const auto& entity : entities)
            {
                handleEntity(entity);
            }
        }

        static void handleEntity(const std::shared_ptr<engine::Entity>& entity)
        {
            for (const auto& currentKey : entity->addOrGetComponent<engine::InputComponent>()->keysFilter)
            {
                auto transformComponent = entity->addOrGetComponent<engine::TransformComponent>();

                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::A)
                {
                    transformComponent->velocity.x = -1;
                    return;
                }
                else if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::D)
                {
                    transformComponent->velocity.x = 1;
                    return;
                }
                else
                {
                    transformComponent->velocity.x = 0;
                }
            }
        }
    };
}