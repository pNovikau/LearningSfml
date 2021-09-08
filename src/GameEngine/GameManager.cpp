// GameManager.cpp : Source file for your target.
//

#include <Systems/DrawSystem.h>
#include <Systems/TransformSystem.h>
#include "GameManager.h"
#include "FPS.h"

namespace engine
{
	GameManager::GameManager(const unsigned int width, const unsigned int height, const std::string& title)
		: title_(title)
	{
		window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title_);
		object_manager_ = std::make_shared<GameObjectManager>();

        _systemManager = std::make_shared<SystemManager>();
        _entityManager = std::make_shared<EntityManager>();
	}

	void GameManager::init() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = window_;

        for (const auto& entity : _entityManager->listEntities())
        {
            entity->init(context);
        }

        TransformSystem transformSystem(_entityManager);
        _systemManager->registerSystem(transformSystem);

        DrawSystem drawSystem(_entityManager);
        _systemManager->registerSystem(drawSystem);
	}

	void GameManager::start() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = window_;
		context->time = std::make_shared<GameTime>();

        auto entityManager = std::make_shared<EntityManager>();
        DrawSystem drawSystem(entityManager);

		Utility::FPS fps(context->time);

		while (window_->isOpen())
		{
			sf::Event event{};

			while (window_->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window_->close();
			}

			window_->clear();

            for (const auto& system : _systemManager->listSystem())
            {
                system->update(context);
            }

			std::uint8_t frames = fps.getFPS();
			window_->setTitle(title_ + " FPS: " + std::to_string(frames));

            context->time->update();

			window_->display();
		}
	}

	std::shared_ptr<GameObjectManager> GameManager::get_object_manager() const
	{
		return object_manager_;
	}

}