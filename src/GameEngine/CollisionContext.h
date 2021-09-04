#pragma once
#include "memory"

namespace engine
{
	class GameObject;

	struct CollisionContext
	{
		std::shared_ptr<GameObject> game_object;
	};
}
