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
		object_manager_ = std::make_shared<GameObjectManager>();
	}

	void GameManager::init() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = window_;

		for (const auto& game_obj : object_manager_->list())
		{
			game_obj->init();
		}
	}

	void GameManager::start() const
	{
		auto context = std::make_unique<GameContext>();
		context->window = window_;

		while (window_->isOpen())
		{
			sf::Event event{};

			while(window_->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window_->close();

				for (const auto& game_obj : object_manager_->list())
				{
					game_obj->handle_event(event);
				}
			}

			window_->clear();

			for (const auto& game_obj : object_manager_->list())
			{
				game_obj->updated(context);
			}

			window_->display();
			//sf::Event event;
			//
			//while (window_->pollEvent(event))
			//{
			//	handle_event(event);
			//}
		}
	}

	std::shared_ptr<GameObjectManager> GameManager::get_object_manager() const
	{
		return object_manager_;
	}


	//void GameManager::handle_event(const sf::Event& event) const
	//{
	//	if (event.type == sf::Event::Closed)
	//	{
	//		WindowClosedEvent windowClosedEvent;
	//
	//		event_manager_->raise_event(windowClosedEvent);
	//	}
	//	else if (event.type == sf::Event::KeyPressed)
	//	{}
	//}

}