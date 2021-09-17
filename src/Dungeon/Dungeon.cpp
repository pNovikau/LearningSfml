// Dungeon.cpp : Source file for your target.
//

#include "GameManager.h"

#include "BigDemon.h"
#include "BidZombie.h"
#include "Floor.h"
#include "Coin.h"

#include "EnemyMoveSystem.h"
#include "EnemyControlSystem.h"
#include "AnimationStateSystem.h"

#include "LevelGenerator.h"

int main()
{
    engine::GameManager gameManager(768, 1024, "yey");

    gameManager.loadResources("C:\\Work\\sandbox\\repos\\LearningSfml\\src\\Dungeon\\Resources\\Assets");

    auto level = dungeon::utils::LevelGenerator::getLevel();

    for (const auto &floor : level.floors)
    {
        auto floorEntity = gameManager.addEntity<dungeon::entities::Floor>();
        floorEntity->setPosition(floor);
    }

    gameManager.addEntity<dungeon::entities::BigDemon>();
    gameManager.addEntity<dungeon::entities::BidZombie>();
    gameManager.addEntity<dungeon::entities::Coin>();

    gameManager.registerSystem<dungeon::systems::EnemyControlSystem>();
    gameManager.registerSystem<dungeon::systems::EnemyMoveSystem>();
    gameManager.registerSystem<dungeon::systems::AnimationStateSystem>();

    gameManager.init();
    gameManager.start();

	return 0;
}
