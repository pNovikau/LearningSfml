#pragma once

#include <SFML/Graphics.hpp>
#include "memory"

namespace engine
{
	struct GameContext
	{
		std::shared_ptr<sf::RenderWindow> window;
	};
}