#pragma once
#include <vector>

#include "memory"
#include "SFML/System.hpp"

namespace engine
{
	class GameObject;

	//TODO:
	template <typename T>
	struct ContactPoint
	{
		T x;
		T y;
		sf::Vector2<T> normal;
	};

	struct CollisionContext
	{
		std::shared_ptr<GameObject> game_object;
		std::vector<ContactPoint<float>> contacts;
	};
}
