#include "Wall.h"

namespace game
{
	void Wall::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto shape = std::make_shared<sf::RectangleShape>(size_);
		shape->setFillColor(sf::Color::Transparent);
		shape->setPosition(position_);
		shape->setSize(size_);

		shape_ = shape;
	}

	void Wall::updated(const std::unique_ptr<engine::GameContext>& context)
	{ }

	void Wall::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{ }


	void Wall::set_size(const sf::Vector2f& size)
	{
		size_ = size;
	}

	void Wall::set_position(const sf::Vector2f& position)
	{
		position_ = position;
	}
}
