#pragma once
#include "Objects/CollidingGameObject.h"
#include "CollisionContext.h"
#include "GameContext.h"
#include "ScoreManager.h"

namespace game
{
	class EnemyTrigger : public engine::CollidingGameObject
	{
		using CollidingGameObject::CollidingGameObject;

	public:
		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

		void set_score_manager(const std::shared_ptr<ScoreManager>& score_manager);

	private:
		std::shared_ptr<ScoreManager> score_manager_;
	};
}
