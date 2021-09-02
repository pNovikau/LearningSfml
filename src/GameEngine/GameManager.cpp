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
			game_obj->init(context);
		}
	}

	void GameManager::start() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = window_;
		context->events = std::make_shared<std::vector<sf::Event>>();

		while (window_->isOpen())
		{
			sf::Event event{};

			while(window_->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window_->close();

				context->events->push_back(event);
			}

			window_->clear();

			for (const auto& game_obj : object_manager_->list())
			{
				game_obj->updated(context);
			}

			window_->display();
			context->events->clear();
		}
	}

	std::shared_ptr<GameObjectManager> GameManager::get_object_manager() const
	{
		return object_manager_;
	}

}