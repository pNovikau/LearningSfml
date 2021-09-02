#pragma once
#include "Events/Event.h"

namespace engine
{
	class IEventHandler
	{
	public:
		virtual void Handle(const Event &event);
	};
}