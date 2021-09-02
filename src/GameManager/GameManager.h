#pragma once

#include <SFML/Graphics.hpp>

#include "EventManager.h"

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


		void init();
		void start();

	private:
		std::shared_ptr<sf::RenderWindow> window_;
		std::shared_ptr<EventManager> event_manager_;

		void handle_event(const sf::Event& event) const;
	};

	static class Constants
	{
	public:
		static class Entities
		{
		public:
			const std::string Player = "entity_player";
			const std::string Enemy = "entity_enemy";
		};
	};

}
