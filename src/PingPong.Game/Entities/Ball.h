#pragma once
#include <random>
#include <ECS/Entity.h>

#include "CollidingGameObject.h"
#include "ScoreManager.h"
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

            const sf::Vector2f shape_position(window_size.x / 2.0f, window_size.y / 2.0f);
            const auto shape = std::make_shared<sf::CircleShape>(radius_);
            shape->setFillColor(sf::Color::White);
            shape->setPosition(shape_position);
            shape->setOrigin(10.f, 10.f);

            const auto& transformComponent = this->addOrGetComponent<engine::TransformComponent>();
            transformComponent->transformable = shape;
            transformComponent->velocity = Utility::normalise({ -0.5f, 0.1f });
            transformComponent->speed = speed_;

            const auto& collidingComponent = this->addOrGetComponent<engine::CollidingComponent>();
            collidingComponent->globalBounds = shape->getGlobalBounds();
            collidingComponent->localBounds = shape->getLocalBounds();

            const auto& drawComponent = this->addOrGetComponent<engine::DrawComponent>();
            drawComponent->drawable = shape;
        }


	private:
		const float radius_ = 10.0f;
		const float speed_ = 300.f;
	};
}
