#pragma once
#include "CollidingGameObject.h"

namespace game
{
	class PlayerTrigger : public engine::CollidingGameObject
	{
		using CollidingGameObject::CollidingGameObject;

	public:
		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;
	};
};
