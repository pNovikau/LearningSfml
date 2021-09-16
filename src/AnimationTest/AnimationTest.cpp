#include "GameManager.h"

#include "Player.h"
#include "PlayerInputSystem.h"
#include "PlayerAnimationSystem.h"


int main()
{
    engine::GameManager gameManager(768, 1024, "yey");

    gameManager.loadResources("C:\\Work\\sandbox\\repos\\LearningSfml\\src\\AnimationTest\\Resources\\Knight");

    gameManager.addEntity<Player>(Constants::Entities::PLAYER_ID);

    gameManager.registerSystem<PlayerInputSystem>();
    gameManager.registerSystem<PlayerAnimationSystem>();

    gameManager.init();
    gameManager.start();

	return 0;
}
