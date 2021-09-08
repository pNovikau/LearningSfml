// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <random>
#include <Systems/CollidingSystem.h>

#include "GameManager.h"
#include "Constants.h"
#include "Ball.h"
#include "Player.h"
#include "Wall.h"
#include "PlayerTrigger.h"
#include "EnemyTrigger.h"
#include "Score.h"
#include "ScoreManager.h"
#include "Systems/InputSystem.h"

int main()
{
	auto create_wall = [](const sf::Vector2f position, const sf::Vector2f size)
	{
		game::Wall wall;
		wall.set_origin(size / 2.f);
		wall.set_position(position);
		wall.set_size(size);
		wall.add_tag(game::Constants::Tags::WALL);

		return wall;
	};

	const engine::GameManager game_manager(768, 1024, "yey");

    game_manager.addEntity<game::Player>(game::Constants::Entities::PLAYER_ID);

    game_manager.registerSystem<game::CollidingSystem>();
    game_manager.registerSystem<game::InputSystem>();

	game_manager.init();
	game_manager.start();

	return 0;
}


