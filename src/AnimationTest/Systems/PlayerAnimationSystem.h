#pragma once

#include "System.h"
#include <Events/IEventHander.h>
#include "AnimationComponent.h"

#include "Constants.h"
#include "KeyPressedEvent.h"

class PlayerAnimationSystem :
        public engine::System,
        public engine::IEventHandler<KeyPressedEvent>
{
    void init(const std::unique_ptr<engine::GameContext>& context) override
    {
        _runTexture = _resourceManager->getTexture("player_run");
        _idleTexture = _resourceManager->getTexture("player_idle");

        subscribe<KeyPressedEvent>();
    }

    void update(const std::unique_ptr<engine::GameContext> &context) override
    {
        if (_currentState == IDLE)
            return;

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            auto entity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);
            auto animationComponent = entity->tryGetComponent<engine::AnimationComponent>();

            auto size = _idleTexture->getSize();
            int height = size.y;
            int offset = size.x / _idleFrames;

            animationComponent->offset = offset;
            animationComponent->currentDelay = 0;
            animationComponent->currentFrame = 0;
            animationComponent->totalFrames = _idleFrames;
            animationComponent->sprite->setTexture(*_idleTexture);
            animationComponent->sprite->setTextureRect({0, 0, offset, height});

            _currentState = IDLE;
        }
    }

    void handleEvent(const KeyPressedEvent& event) override
    {
        if (event.currentEntityId != Constants::Entities::PLAYER_ID)
            return;

        auto entity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);
        auto animationComponent = entity->tryGetComponent<engine::AnimationComponent>();

        if (_currentState == IDLE)
        {
            auto size = _runTexture->getSize();
            int height = size.y;
            int offset = size.x / _runFrames;

            animationComponent->offset = offset;
            animationComponent->currentDelay = 0;
            animationComponent->currentFrame = 0;
            animationComponent->totalFrames = _runFrames;
            animationComponent->sprite->setTexture(*_runTexture);
            animationComponent->sprite->setTextureRect({0, 0, offset, height});
        }

        if (event.key == sf::Keyboard::A && _currentState != RUN_LEFT)
        {
            animationComponent->sprite->setScale(-1.f, 1.f);
            _currentState = RUN_LEFT;
            return;
        }

        if (event.key == sf::Keyboard::D && _currentState != RUN_RIGHT)
        {
            animationComponent->sprite->setScale(1.f, 1.f);
            _currentState = RUN_RIGHT;
            return;
        }
    }

    template<typename TEvent>
    void subscribe()
    {
        _eventManager->subscribe<TEvent>([this]<typename TCollisionEvent>(TCollisionEvent && event)
        {
            handleEvent(std::forward<TCollisionEvent>(event));
        });
    }

private:
    const std::string IDLE = "idle";
    const std::string RUN_LEFT = "run_left";
    const std::string RUN_RIGHT = "run_right";

    std::shared_ptr<sf::Texture> _runTexture;
    uint16_t _runFrames = 8;

    std::shared_ptr<sf::Texture> _idleTexture;
    uint16_t _idleFrames = 15;

    std::string _currentState;
};