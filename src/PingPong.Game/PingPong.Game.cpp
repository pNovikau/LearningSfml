// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <Systems/PlayerSystem.h>
#include <Systems/BallBounceSystem.h>
#include <Systems/TriggerSystem.h>
#include <Systems/GameResetSystem.h>

#include "GameManager.h"
#include "Player.h"
#include "Wall.h"
#include "Trigger.h"
#include "Systems/InputSystem.h"

int main()
{
	const engine::GameManager game_manager(768, 1024, "yey");

    game_manager.addEntity<game::Player>(game::Constants::Entities::PLAYER_ID);
    game_manager.addEntity<game::Ball>(game::Constants::Entities::BALL_ID);

    auto leftWall = game_manager.addEntity<game::Wall>();
    leftWall->setPosition({68, 5});
    leftWall->setSize({10, 1000});

    auto rightWall = game_manager.addEntity<game::Wall>();
    rightWall->setPosition({700, 5});
    rightWall->setSize({10, 1000});

    auto topTrigger = game_manager.addEntity<game::Trigger>();
    topTrigger->setPosition({69, 0});
    topTrigger->setSize({631, 5});

    auto bottomTrigger = game_manager.addEntity<game::Trigger>();
    bottomTrigger->setPosition({69, 1020});
    bottomTrigger->setSize({631, 5});

    game_manager.registerSystem<game::TriggerSystem>();
    game_manager.registerSystem<game::PlayerSystem>();
    game_manager.registerSystem<game::InputSystem>();
    game_manager.registerSystem<game::BallBounceSystem>();
    game_manager.registerSystem<game::GameResetSystem>();

	game_manager.init();
	game_manager.start();

	return 0;
}


