#pragma once
#include <random>

#include "GameObject.h"

namespace game
{
	class Ball : public engine::GameObject
	{
	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

	private:
		const float radius_ = 10.0f;
		const float speed_ = 0.13f;

		std::unique_ptr<sf::Vector2f> direction_;

		static int random_angle();
		static void set_new_direction(std::unique_ptr<sf::Vector2f>& direction);
	};
}
