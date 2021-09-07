#pragma once

namespace engine
{
	enum class GameObjectType
	{
		collidingObject     = (1u << 0),
        drawableObject      = (1u << 1),
        transformableObject = (1u << 2)
	};
}