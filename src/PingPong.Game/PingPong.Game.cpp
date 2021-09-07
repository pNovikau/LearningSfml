// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <random>

#include "GameManager.h"
#include "Constants.h"
#include "Ball.h"
#include "Player.h"
#include "Wall.h"
#include "PlayerTrigger.h"
#include "EnemyTrigger.h"
#include "Score.h"
#include "ScoreManager.h"

int main()
{
	auto create_wall = [](const sf::Vector2f position, const sf::Vector2f size)
	{
		game::Wall wall;
		wall.set_origin(size / 2.f);
		wall.set_position(position);
		wall.set_size(size);
        wall.addTag(game::Constants::Tags::WALL);

		return wall;
	};

	const engine::GameManager game_manager(768, 1024, "yey");
	
	const auto player = std::make_shared<game::Player>(game::Constants::Entities::PLAYER_ID);
	game_manager.get_object_manager()->add(player);

	const auto score = std::make_shared<game::Score>();
	game_manager.get_object_manager()->add(score);

	const auto ball = std::make_shared<game::Ball>(game::Constants::Entities::BALL_ID);
	game_manager.get_object_manager()->add(ball);

	//left
	auto wall = create_wall({ 20.f, 400.f }, { 20.f, 760.f } );
	game_manager.get_object_manager()->add(std::make_shared<game::Wall>(wall));

	//right
	wall = create_wall({ 590.f, 400.f }, { 20.f, 760.f });
	game_manager.get_object_manager()->add(std::make_shared<game::Wall>(wall));

	const auto player_trigger = std::make_shared<game::PlayerTrigger>();
	game_manager.get_object_manager()->add(player_trigger);

	const auto enemy_trigger = std::make_shared<game::EnemyTrigger>();
	game_manager.get_object_manager()->add(enemy_trigger);

	const auto score_manager = std::make_shared<game::ScoreManager>(score);
	player_trigger->set_score_manager(score_manager);
	enemy_trigger->set_score_manager(score_manager);

	game_manager.init();
	game_manager.start();

	return 0;
}


