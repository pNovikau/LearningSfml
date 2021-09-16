#pragma once

#include "System.h"
#include "Components/TransformComponent.h"
#include "Components/IntputComponent.h"

#include "Constants.h"
#include "KeyPressedEvent.h"

class PlayerInputSystem : public engine::System
{
    void update(const std::unique_ptr<engine::GameContext> &context) override
    {
        auto playerEntity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);

        for (const auto& currentKey : playerEntity->tryGetComponent<engine::InputComponent>()->keysFilter)
        {
            const auto transformComponent = playerEntity->tryGetComponent<engine::TransformComponent>();

            if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::A)
            {
                KeyPressedEvent event;
                event.key = sf::Keyboard::A;
                event.currentEntityId = Constants::Entities::PLAYER_ID;
                _eventManager->addEvent(event);

                transformComponent->velocity.x = -1;
                return;
            }

            if (sf::Keyboard::isKeyPressed(currentKey) && currentKey == sf::Keyboard::D)
            {
                KeyPressedEvent event;
                event.key = sf::Keyboard::D;
                event.currentEntityId = Constants::Entities::PLAYER_ID;
                _eventManager->addEvent(event);

                transformComponent->velocity.x = 1;
                return;
            }

            transformComponent->velocity.x = 0;
        }


    }
};

