#include "Wall.h"

namespace game
{
	void Wall::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto shape = std::make_shared<sf::RectangleShape>(size_);
		shape->setFillColor(sf::Color::Transparent);
		shape->setSize(size_);
		shape->setOrigin(origin_);
		shape->setPosition(position_);

		shape_ = shape;
		drawable_ = shape;
		transformable_ = shape;
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
	void Wall::set_origin(const sf::Vector2f& origin)
	{
		origin_ = origin;
	}
}
