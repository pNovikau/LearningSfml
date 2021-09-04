#pragma once
#include <memory>

#include "Score.h"

namespace game
{
	class ScoreManager
	{
	public:
		ScoreManager(const std::shared_ptr<Score> score);

		void increment_enemy_score() const;
		void increment_player_score() const;

	private:
		std::shared_ptr<Score> score_;
	};
}

