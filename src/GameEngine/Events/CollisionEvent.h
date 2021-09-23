#pragma once

#include "Entity.h"
#include "Events/Event.h"

namespace engine
{
	class CollisionEvent : public Event<CollisionEvent>
	{
	public:
        sf::FloatRect overlap;
        std::string currentEntityId;
        std::string targetEntityId;
	};
}
