#pragma once
#include <Entity.h>

#include "Utils/VectorMath.h"

#include <Components/TransformComponent.h>
#include <Components/CollidingComponent.h>
#include "Components/DrawComponent.h"

namespace game
{
	class Ball : public engine::Entity
	{
		using Entity::Entity;

	public:
		
		void init(const std::unique_ptr<engine::GameContext>& context) override
        {
            const sf::Vector2u window_size = context->window->getSize();

            defaultPosition = {window_size.x / 2.0f, window_size.y / 2.0f};
            const auto shape = std::make_shared<sf::CircleShape>(_radius);
            shape->setFillColor(sf::Color::White);
            shape->setPosition(defaultPosition);
            shape->setOrigin(10.f, 10.f);

            const auto& transformComponent = this->addComponent<engine::TransformComponent>();
            transformComponent->transformable = shape;
            transformComponent->velocity = Utility::normalise({ 0.f, -1.f });
            transformComponent->speed = _speed;

            const auto& collidingComponent = this->addComponent<engine::CollidingComponent>();
            collidingComponent->globalBounds = shape->getGlobalBounds();
            collidingComponent->localBounds = shape->getLocalBounds();

            const auto& drawComponent = this->addComponent<engine::DrawComponent>();
            drawComponent->drawable = shape;
        }

        sf::Vector2f defaultPosition;

	private:
		const float _radius = 10.0f;
		const float _speed = 300.f;
	};
}
