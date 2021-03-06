#include "EnemyTrigger.h"
#include "Constants.h"

namespace game
{
	void EnemyTrigger::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto window_size = context->window->getSize();

		sf::RectangleShape shape({ static_cast<float>(window_size.x), 2 });
		shape.setPosition(0, static_cast<float>(window_size.y));

		shape_ = std::make_shared<sf::RectangleShape>(shape);
		drawable_ = shape_;
		transformable_ = shape_;
	}

	void EnemyTrigger::collision(const std::unique_ptr<engine::CollisionContext>& context)
	{
		if (context->game_object->get_id() != Constants::Entities::BALL_ID)
			return;

		score_manager_->increment_enemy_score();
	}

	void EnemyTrigger::updated(const std::unique_ptr<engine::GameContext>& context)
	{ }

	void EnemyTrigger::set_score_manager(const std::shared_ptr<ScoreManager>& score_manager)
	{
		score_manager_ = score_manager;
	}
}