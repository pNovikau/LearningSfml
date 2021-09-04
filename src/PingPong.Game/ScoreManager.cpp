#include "ScoreManager.h"

namespace game
{
	ScoreManager::ScoreManager(const std::shared_ptr<Score> score)
	{
		score_ = score;
	}

	void ScoreManager::increment_player_score() const
	{
		score_->increment_player_score();
	}

	void ScoreManager::increment_enemy_score() const
	{
		score_->increment_enemy_score();
	}
}
