#pragma once

#include <SFML/Graphics.hpp>
#include "memory"

namespace engine
{
	struct GameContext
	{
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<std::vector<sf::Event>> events;
	};
}