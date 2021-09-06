#pragma once

#include <SFML/Graphics.hpp>
#include "memory"
#include "GameTime.h"

namespace engine
{
	struct GameContext
	{
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<GameTime> time;
	};
}