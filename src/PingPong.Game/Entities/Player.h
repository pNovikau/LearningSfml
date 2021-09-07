#pragma once

#include <DrawableObject.h>
#include "Objects/CollidingObject.h"
#include "GameContext.h"

namespace game
{
    class Player :
        public engine::DrawableObject,
        public engine::CollidingObject
	{
		using DrawableObject::DrawableObject;

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
