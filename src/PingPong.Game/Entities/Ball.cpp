#include "Ball.h"
#include "iostream"
#include "Constants.h"

namespace game
{
	void Ball::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const sf::Vector2u window_size = context->window->getSize();

		const sf::Vector2f shape_position(window_size.x / 2.0f, window_size.y / 2.0f);
		const auto shape = std::make_shared<sf::CircleShape>(radius_);
		shape->setFillColor(sf::Color::White);
		shape->setPosition(shape_position);
		
		shape_ = shape;
		drawable_ = shape;
		transformable_ = shape;

		direction_ = std::make_unique<sf::Vector2f>(0.5, -0.2);
	}

	void Ball::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto& shape_position = shape_->getPosition();

		shape_->move(direction_->x * speed_, direction_->y * speed_);
	}

	void Ball::draw(const std::unique_ptr<engine::GameContext>& context) const
	{
		context->window->draw(*shape_);
	}

	void Ball::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		if (context->game_object->get_tags()->contains(Constants::Tags::WALL))
			direction_->x *= -1;
		else if (context->game_object->get_id() == Constants::Entities::PLAYER_ID)
			direction_->y *= -1;

		std::cout << "collision";
	}
}
