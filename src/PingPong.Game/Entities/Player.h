#pragma once
#include "CollidingGameObject.h"
#include "GameContext.h"

namespace game
{
	class Player : public engine::CollidingGameObject
	{
		using CollidingGameObject::CollidingGameObject;

	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

	private:
		const float speed_ = 0.15f;

		bool can_move_left_ = true;
		bool can_move_right_ = true;
	};
}
