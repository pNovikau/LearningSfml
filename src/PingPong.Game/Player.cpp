#include "Player.h"

namespace game
{
	void Player::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto window_size = context->window->getSize();
		sf::Vector2f rectangle_size(150, 20);

		const auto shape = std::make_shared<sf::RectangleShape>(rectangle_size);
		shape->setFillColor(sf::Color::White);
		shape->setPosition(window_size.x / 2.0f, 5.0f);
		
		shape_ = shape;
	}

	void Player::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shape_->move(-speed_, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shape_->move(speed_, 0);
		}

		context->window->draw(*shape_);
		draw_collision_box(context);
	}

	void Player::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{ }
}
