#pragma once

#include <SFML/Graphics.hpp>

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

	private:
		std::shared_ptr<sf::RenderWindow> window_;
		std::shared_ptr<GameObjectManager> object_manager_;
		std::string title_;
	};

	class Constants
	{
	public:
		class Entities
		{
		public:
			const std::string Player = "entity_player";
			const std::string Enemy = "entity_enemy";
		};
	};

}
