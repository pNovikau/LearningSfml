#pragma once

#include "Constants.h"
#include <Entity.h>
#include <Components/TransformComponent.h>
#include <Components/TriggerComponent.h>
#include "Components/DrawComponent.h"

namespace game
{
    class Trigger : public engine::Entity
    {
        using Entity::Entity;

    public:

        void init(const std::unique_ptr<engine::GameContext>& context) override
        {
            const auto shape = std::make_shared<sf::RectangleShape>(_size);
            shape->setFillColor(sf::Color::White);
            shape->setSize(_size);
            shape->setOrigin(_origin);
            shape->setPosition(_position);

            const auto& transformComponent = this->addComponent<engine::TransformComponent>();
            transformComponent->transformable = shape;

            const auto& triggerComponent = this->addComponent<TriggerComponent>();
            triggerComponent->body = shape->getGlobalBounds();
        }

        void setSize(const sf::Vector2f& size) { _size = size; }
        void setPosition(const sf::Vector2f& position) { _position = position; }
        void set_origin(const sf::Vector2f& origin) { _origin = origin; }

    private:
        sf::Vector2f _size;
        sf::Vector2f _position;
        sf::Vector2f _origin;
    };
}
