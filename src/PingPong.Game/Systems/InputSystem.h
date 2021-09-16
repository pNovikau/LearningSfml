#pragma once

#include "Systems/System.h"
#include "Components/TransformComponent.h"
#include "Components/IntputComponent.h"
#include "Events/CollisionEvent.h"

namespace game
{
    class InputSystem :
		public engine::System
    {
    public:
        void init(const std::unique_ptr<engine::GameContext>& context) override
        {

        }

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
            for (const auto& currentKey : entity->tryGetComponent<engine::InputComponent>()->keysFilter)
            {
	            const auto transformComponent = entity->tryGetComponent<engine::TransformComponent>();

                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::A)
                {
                    transformComponent->velocity.x = -1;
                    return;
                }

                if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::D)
                {
	                transformComponent->velocity.x = 1;
	                return;
                }

                transformComponent->velocity.x = 0;
            }
        }
    };
}