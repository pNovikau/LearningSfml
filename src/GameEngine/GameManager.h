﻿#pragma once

#include <SFML/Graphics.hpp>
#include <Managers/SystemManager.h>
#include "Managers/EntityManager.h"
#include "Events/Event.h"

#include "GameObjectManager.h"

namespace engine
{
	class GameManager
	{
	public:
		GameManager() = delete;
		GameManager(const GameManager& other) = delete;
		GameManager& operator=(const GameManager& other) = delete;
		GameManager(GameManager&& other) = delete;
		GameManager& operator=(GameManager&& other) = delete;

		GameManager(unsigned int width, unsigned int height, const std::string& title);


		void init() const;
		void start() const;
		std::string& getTitle() const;
		std::shared_ptr<GameObjectManager> get_object_manager() const;

        template<class TSystem>
        std::shared_ptr<TSystem> registerSystem() const
        {
            TSystem system(_entityManager, _eventManager);

            return _systemManager->registerSystem(system);
        }

        template<class TEntity>
        std::shared_ptr<TEntity> addEntity(std::string id) const
        {
            TEntity entity(id);
            return _entityManager->addEntity(entity);
        }

        template<class TEntity>
        std::shared_ptr<TEntity> addEntity() const
        {
            return _entityManager->createEntity<TEntity>();
        }

	private:
		std::shared_ptr<sf::RenderWindow> window_;
		std::shared_ptr<GameObjectManager> object_manager_;
		std::string title_;

        std::shared_ptr<SystemManager> _systemManager;
        std::shared_ptr<EntityManager> _entityManager;
        std::shared_ptr<EventManager> _eventManager;
	};
}
