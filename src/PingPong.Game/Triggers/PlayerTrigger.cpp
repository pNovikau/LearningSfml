#include "PlayerTrigger.h"
#include "Constants.h"

namespace game
{
	void PlayerTrigger::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto window_size = context->window->getSize();

		sf::RectangleShape shape({ static_cast<float>(window_size.x), 2});

		shape_ = std::make_shared<sf::RectangleShape>(shape);
		drawable_ = shape_;
		transformable_ = shape_;
	}

	void PlayerTrigger::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		if (context->game_object->getId() != Constants::Entities::BALL_ID)
			return;

		if (score_manager_)
			score_manager_->increment_player_score();
	}

	void PlayerTrigger::updated(const std::unique_ptr<engine::GameContext>& context)
	{ }

	void PlayerTrigger::set_score_manager(const std::shared_ptr<ScoreManager>& score_manager)
	{
		score_manager_ = score_manager;
	}

}
