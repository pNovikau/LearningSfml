#pragma once
#include "GameContext.h"
#include "Objects/GameObject.h"

namespace game
{
	class Score : public engine::GameObject
	{
		using GameObject::GameObject;

	public:
		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;

		void increment_player_score();
		void increment_enemy_score();

	private:
		int enemy_score_ = 0;
		int player_score_ = 0;

		std::shared_ptr<sf::Text> text_;
	};
}
