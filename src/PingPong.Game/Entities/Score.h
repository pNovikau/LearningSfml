#pragma once

#include <DrawableObject.h>
#include "GameContext.h"

namespace game
{
	class Score : public engine::DrawableObject
	{
		using DrawableObject::DrawableObject;

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
