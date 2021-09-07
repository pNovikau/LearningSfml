#include "Player.h"
#include "Constants.h"

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
		drawable_ = shape;
		transformable_ = shape;
	}

	void Player::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && can_move_left_)
		{
			shape_->move(-speed_, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && can_move_right_)
		{
			shape_->move(speed_, 0);
		}

		can_move_left_ = true;
		can_move_right_ = true;
	}

	void Player::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		const auto& game_object = context->game_object;
		const bool is_wall = game_object->get_tags()->contains(Constants::Tags::WALL);

		if (!is_wall)
			return;

		if (game_object->get_position().x == 0)
			can_move_left_ = false;
		else
			can_move_right_ = false;
	}
}
