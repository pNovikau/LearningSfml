// GameManager.cpp : Source file for your target.
//

#include <Systems/DrawSystem.h>
#include <Systems/TransformSystem.h>
#include <Systems/CollidingSystem.h>
#include "GameManager.h"
#include "FPS.h"

namespace engine
{
	GameManager::GameManager(const unsigned int width, const unsigned int height, const std::string& title)
		: _title(title)
	{
		_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), _title);

        _resourceManager = std::make_shared<ResourceManager>();
        _systemManager = std::make_shared<SystemManager>();
        _entityManager = std::make_shared<EntityManager>();
		_eventManager = std::make_shared<EventManager>();
	}

	void GameManager::init() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = _window;

        for (const auto& entity : _entityManager->listEntities())
        {
            entity->init(context);
        }

        CollidingSystem collidingSystem(_entityManager, _eventManager);
        _systemManager->registerSystem(collidingSystem);

        TransformSystem transformSystem(_entityManager, _eventManager);
        _systemManager->registerSystem(transformSystem);

        DrawSystem drawSystem(_entityManager, _eventManager);
        _systemManager->registerSystem(drawSystem);

		for (const auto& system : _systemManager->listSystem())
		{
			system->init(context);
		}
	}

	void GameManager::start() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = _window;
		context->time = std::make_shared<GameTime>();

		Utility::FPS fps(context->time);

		while (_window->isOpen())
		{
			sf::Event event{};

			while (_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window->close();
			}

			_window->clear();

            for (const auto& system : _systemManager->listSystem())
            {
                system->update(context);
            }

			std::uint8_t frames = fps.getFPS();
			_window->setTitle(_title + " FPS: " + std::to_string(frames));

			_eventManager->notifyAll();

            context->time->update();

			_window->display();
		}
	}

}