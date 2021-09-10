// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <random>
#include <Systems/PlayerSystem.h>
#include <Systems/BallBounceSystem.h>

#include "GameManager.h"
#include "Ball.h"
#include "Player.h"
#include "Wall.h"
#include "Systems/InputSystem.h"

int main()
{
	const engine::GameManager game_manager(768, 1024, "yey");

    game_manager.addEntity<game::Player>(game::Constants::Entities::PLAYER_ID);
    game_manager.addEntity<game::Ball>(game::Constants::Entities::BALL_ID);

    auto leftWall = game_manager.addEntity<game::Wall>();
    leftWall->set_position({68, 5});
    leftWall->set_size({10, 1000});

    auto rightWall = game_manager.addEntity<game::Wall>();
    rightWall->set_position({700, 5});
    rightWall->set_size({10, 1000});

    game_manager.registerSystem<game::PlayerSystem>();
    game_manager.registerSystem<game::InputSystem>();
    game_manager.registerSystem<game::BallBounceSystem>();

	game_manager.init();
	game_manager.start();

	return 0;
}


