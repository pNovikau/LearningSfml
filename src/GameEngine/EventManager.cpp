#include "EventManager.h"

namespace engine
{
	void EventManager::RaiseEvent(const Event &event)
	{
		for (const auto handler : handlers)
		{
			handler->Handle(event);
		}
	}

	void EventManager::SubscribeOnEvents(std::shared_ptr<IEventHandler> handler)
	{
		handlers.push_back(handler);
	}
}