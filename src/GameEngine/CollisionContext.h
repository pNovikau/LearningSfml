#pragma once
#include "memory"

#include <SFML/Graphics/Rect.hpp>

namespace engine
{
	class GameObject;

	struct CollisionContext
	{
		std::shared_ptr<GameObject> game_object;
		sf::FloatRect overlap;
	};
}
