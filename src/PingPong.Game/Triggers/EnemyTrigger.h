#pragma once
#include "CollidingGameObject.h"
#include "CollisionContext.h"
#include "GameContext.h"

namespace game
{
	class EnemyTrigger : public engine::CollidingGameObject
	{
		using CollidingGameObject::CollidingGameObject;

	public:
		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;
	};
}
