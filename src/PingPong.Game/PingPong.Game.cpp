// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <random>

#include "GameManager.h"
#include "Constants.h"
#include "Ball.h"
#include "Player.h"
#include "Wall.h"


int main()
{
	auto create_wall = [](const sf::Vector2f position, const sf::Vector2f size)
	{
		game::Wall wall;
		wall.set_size(size);
		wall.set_position(position);
		wall.add_tag(game::Constants::Tags::WALL);

		return wall;
	};

	const engine::GameManager game_manager(1200, 1200, "yey");
	
	const auto player = std::make_shared<game::Player>(game::Constants::Entities::PLAYER_ID);
	game_manager.get_object_manager()->add(player);

	const auto ball = std::make_shared<game::Ball>(game::Constants::Entities::BALL_ID);
	game_manager.get_object_manager()->add(ball);

	auto wall = create_wall({ 0, 0 }, { 1, 1200 });
	game_manager.get_object_manager()->add(std::make_shared<game::Wall>(wall));

	wall = create_wall({ 1198, 0 }, { 1, 1200 });
	game_manager.get_object_manager()->add(std::make_shared<game::Wall>(wall));

	wall = create_wall({ 0, 0 }, { 1200, 1 });
	game_manager.get_object_manager()->add(std::make_shared<game::Wall>(wall));

	wall = create_wall({ 0, 1198 }, { 1200, 1 });
	game_manager.get_object_manager()->add(std::make_shared<game::Wall>(wall));

	game_manager.init();
	game_manager.start();

	return 0;
}


