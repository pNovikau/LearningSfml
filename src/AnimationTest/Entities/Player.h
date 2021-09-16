#pragma once

#include "Entity.h"
#include "AnimationComponent.h"
#include "DrawComponent.h"
#include "TransformComponent.h"
#include "IntputComponent.h"

class Player : public engine::Entity
{
public:
    using Entity::Entity;

    void init(const std::unique_ptr<engine::GameContext> &context) override
    {
        auto texture = context->resourceManager->getTexture("player_run");
        auto size = texture->getSize();
        auto offset = size.x / 8;

        auto animationComponent = addComponent<engine::AnimationComponent>();
        animationComponent->timeDelay = 0.1;
        animationComponent->offset = offset;
        animationComponent->totalFrames = 8;

        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(sf::IntRect(0, 0, offset, size.y));

        animationComponent->sprite = std::make_shared<sf::Sprite>(sprite);

        auto localBounds = animationComponent->sprite->getLocalBounds();
        animationComponent->sprite->setOrigin(localBounds.width / 2, 0);

        auto drawComponent = addComponent<engine::DrawComponent>();
        drawComponent->drawable = animationComponent->sprite;

        const sf::Vector2u window_size = context->window->getSize();
        auto transformableComponent = addComponent<engine::TransformComponent>();
        transformableComponent->transformable = animationComponent->sprite;
        transformableComponent->speed = 300.f;
        transformableComponent->transformable->setPosition({window_size.x / 2.0f, window_size.y / 2.0f});

        auto inputComponent = addComponent<engine::InputComponent>();
        inputComponent->keysFilter = { sf::Keyboard::Key::A, sf::Keyboard::Key::D };
    }
};