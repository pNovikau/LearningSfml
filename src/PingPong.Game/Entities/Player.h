#pragma once

#include <Entity.h>
#include <Components/TransformComponent.h>
#include <Components/IntputComponent.h>
#include <Components/CollidingComponent.h>
#include "Components/DrawComponent.h"

namespace game
{
	class Player : public engine::Entity
	{
	public:

        explicit Player(std::string id) : Entity(id) { }

        void init(const std::unique_ptr<engine::GameContext> &context) override
        {
            const auto window_size = context->window->getSize();
            sf::Vector2f rectangle_size(150, 20);

            const auto shape = std::make_shared<sf::RectangleShape>(rectangle_size);
            shape->setFillColor(sf::Color::White);
            shape->setPosition(window_size.x / 2.f, window_size.y - 25.f);

            const auto transformComponent = this->addComponent<engine::TransformComponent>();
            transformComponent->speed = _speed;
            transformComponent->transformable = shape;

            const auto inputComponent = this->addComponent<engine::InputComponent>();
            inputComponent->keysFilter = { sf::Keyboard::Key::A, sf::Keyboard::Key::D };
            
            const auto collidingComponent = this->addComponent<engine::CollidingComponent>();
            collidingComponent->globalBounds = shape->getGlobalBounds();
            collidingComponent->localBounds = shape->getLocalBounds();

            const auto drawComponent = this->addComponent<engine::DrawComponent>();
            drawComponent->drawable = shape;
        }

	private:
		const float _speed = 150.f;
	};
}
