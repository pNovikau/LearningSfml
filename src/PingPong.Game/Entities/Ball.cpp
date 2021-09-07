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
		shape->setOrigin(10.f, 10.f);

        _shape = shape;
        _drawable = shape;
        _transformable = shape;
	}

	void Ball::updated(const std::unique_ptr<engine::GameContext>& context)
	{
        move(velocity_ * speed_ * context->time->get_delta().asSeconds());
	}

	void Ball::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		if (context->game_object->getTags()->contains(Constants::Tags::WALL))
		{
			auto collisionNormal = context->game_object->getPosition() - _transformable->getPosition();
			auto manifold = Utility::getManifold(context->overlap, collisionNormal);
			resolve(manifold);
		}

		std::cout << "[" + CollidingObject::getId() + "] collision with [" + context->game_object->getId() + "] \n";
	}

	void Ball::resolve(const sf::Vector3f& manifold)
	{
		sf::Vector2f normal(manifold.x, manifold.y);
		move(normal * manifold.z);

		velocity_ = Utility::reflect(velocity_, normal);
	}
}
