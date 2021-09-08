#include <Components/TransformComponent.h>
#include <Components/IntputComponent.h>
#include <Components/CollidingComponent.h>
#include "Player.h"
#include "Components/DrawComponent.h"

namespace game
{
	void Player::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto window_size = context->window->getSize();
		sf::Vector2f rectangle_size(150, 20);

		const auto shape = std::make_shared<sf::RectangleShape>(rectangle_size);
		shape->setFillColor(sf::Color::White);
		shape->setPosition(window_size.x / 2.0f, 5.0f);

        auto transformComponent = this->addOrGetComponent<engine::TransformComponent>();
        transformComponent->speed = _speed;
        transformComponent->transformable = shape;

        auto inputComponent = this->addOrGetComponent<engine::InputComponent>();
        inputComponent->keysFilter = { sf::Keyboard::Key::A, sf::Keyboard::Key::D };

        auto collidingComponent = this->addOrGetComponent<engine::CollidingComponent>();
        collidingComponent->collidingBody = std::make_shared<sf::FloatRect>(shape->getGlobalBounds());

        auto drawComponent = this->addOrGetComponent<engine::DrawComponent>();
        drawComponent->drawable = shape;
	}
}
