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
		
		shape_ = shape;
		drawable_ = shape;
		transformable_ = shape;
	}

	void Ball::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		shape_->move(velocity_ * speed_ * context->dt);
	}

	void Ball::draw(const std::unique_ptr<engine::GameContext>& context) const
	{
		context->window->draw(*shape_);
	}

	void Ball::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		if (context->game_object->get_tags()->contains(Constants::Tags::WALL))
		{
			auto collisionNormal = context->game_object->get_position() - transformable_->getPosition();
			auto manifold = Utility::getManifold(context->overlap, collisionNormal);
			resolve(manifold);
		}

		std::cout << "[" + this->get_id() + "] collision with [" + context->game_object->get_id() + "] \n";
	}

	void Ball::resolve(const sf::Vector3f& manifold)
	{
		sf::Vector2f normal(manifold.x, manifold.y);
		shape_->move(normal * manifold.z);

		velocity_ = Utility::reflect(velocity_, normal);
	}
}
