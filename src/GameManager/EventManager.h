#pragma once
#include <memory>
#include <vector>

#include "Events/Event.h"
#include "IEventHandler.h"

namespace engine
{
	class EventManager
	{
	public:
		EventManager() = default;

		EventManager(const EventManager& other) = delete;
		EventManager& operator=(const EventManager& other) = delete;
		EventManager(EventManager&& other) = delete;
		EventManager& operator=(EventManager&& other) = delete;
		
		//TODO: figure out how templates works
		void raise_event(const Event &event);
		void subscribe_on_events(std::shared_ptr<IEventHandler> handler);

	private:
		std::vector<std::shared_ptr<IEventHandler>> handlers_;
	};
}
