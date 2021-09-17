#pragma once

#include "optional"

#include "System.h"

#include "Constants.h"
#include "MoveComponent.h"
#include "KeyPressedEvent.h"

class PlayerInputSystem : public engine::System
{
    void update(const std::unique_ptr<engine::GameContext>& context) override
    {
        auto playerEntity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);

        const auto moveComponent = playerEntity->tryGetComponent<MoveComponent>();

        std::optional<KeyPressedEvent> event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (!event.has_value())
                event.emplace();

            event->keys.set(sf::Keyboard::A);

            moveComponent->direction.x = -1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (!event.has_value())
                event.emplace();

            event->keys.set(sf::Keyboard::D);

            moveComponent->direction.x = 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            if (!event.has_value())
                event.emplace();

            event->keys.set(sf::Keyboard::LShift);
        }

        if (!event.has_value() ||
            !event->keys[sf::Keyboard::A] &&
            !event->keys[sf::Keyboard::D])
        {
            moveComponent->direction.x = 0;
        }

        if (event.has_value())
        {
            event->currentEntityId = playerEntity->getId();
            _eventManager->addEvent(event.value());
        }
    }
};

