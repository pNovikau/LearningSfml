// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <random>

#include "GameManager.h"

#include "Ball.h"
#include "Player.h"


int main()
{
	const engine::GameManager game_manager(1200, 1200, "yey");

	const auto player = std::make_shared<game::Player>();
	game_manager.get_object_manager()->add(player);

	const auto ball = std::make_shared<game::Ball>();
	game_manager.get_object_manager()->add(ball);

	game_manager.init();

	game_manager.start();

	return 0;
}
