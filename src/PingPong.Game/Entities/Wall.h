#pragma once
#include "Objects/CollidingObject.h"

namespace game
{
	class Wall : public engine::CollidingObject
	{
		using CollidingObject::CollidingObject;

	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

		void set_size(const sf::Vector2f& size);
		void set_position(const sf::Vector2f& position);
		void set_origin(const sf::Vector2f& origin);

	private:
		sf::Vector2f size_;
		sf::Vector2f position_;
		sf::Vector2f origin_;
	};
}
