#pragma once
#include <random>

#include "CollidingGameObject.h"

namespace game
{
	class Ball : public engine::CollidingGameObject
	{
		using CollidingGameObject::CollidingGameObject;

	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;
		void draw(const std::unique_ptr<engine::GameContext>& context) const override;

	private:
		const float radius_ = 10.0f;
		const float speed_ = 0.23f;
		
		std::unique_ptr<sf::Vector2f> direction_;

		static int random_angle();
		static void set_new_direction(std::unique_ptr<sf::Vector2f>& direction);
	};
}
