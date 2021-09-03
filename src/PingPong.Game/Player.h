#pragma once
#include "GameContext.h"
#include "GameObject.h"

namespace game
{
	class Player : public engine::GameObject
	{
	public:
		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

	private:
		const float speed_ = 0.15f;
	};
}
