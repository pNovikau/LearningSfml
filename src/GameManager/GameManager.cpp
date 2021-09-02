// GameManager.cpp : Source file for your target.
//

#include "GameManager.h"
#include "Events.h"

namespace engine
{
	GameManager::GameManager(const unsigned int width, const unsigned int height, const std::string& title)
	{
		window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
		event_manager_ = std::make_shared<EventManager>();
	}

	void GameManager::init()
	{ }

	void GameManager::start()
	{
		while (window_->isOpen())
		{
			sf::Event event;

			while (window_->pollEvent(event))
			{
				handle_event(event);
			}
		}
	}

	void GameManager::handle_event(const sf::Event& event) const
	{
		if (event.type == sf::Event::Closed)
		{
			WindowClosedEvent windowClosedEvent;

			event_manager_->raise_event(windowClosedEvent);
		}
		else if (event.type == sf::Event::KeyPressed)
		{}
	}

}