#include "Ball.h"
#include "iostream"

namespace game
{
	void Ball::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const sf::Vector2u window_size = context->window->getSize();

		const auto shape = std::make_shared<sf::CircleShape>(radius_);
		shape->setFillColor(sf::Color::White);
		shape->setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
		
		shape_ = shape;

		//direction_ = std::make_unique<sf::Vector2f>(0, -1);
	}

	void Ball::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		//shape_->move(direction_->x * speed_, direction_->y * speed_);
	}

	void Ball::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		std::cout << "collision";
	}
	
	int Ball::random_angle()
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		const std::uniform_int_distribution uni(0, 360);

		return uni(rng);
	}

	void Ball::set_new_direction(std::unique_ptr<sf::Vector2f>& direction)
	{
		
	}

}
