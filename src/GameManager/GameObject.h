#pragma once
#include "SFML/Graphics.hpp"

namespace engine
{
	class GameObject
	{
	public:
		GameObject() = delete;

		GameObject(const std::shared_ptr<sf::RenderWindow>& window);
		GameObject(const std::shared_ptr<sf::RenderWindow>& window, const std::string& id);

		/// <summary>
		/// Is called once per frame
		/// </summary>
		virtual void updated() = 0;

		std::string get_id() const;

	protected:
		std::shared_ptr<sf::RenderWindow> window_;
		std::string id_;
	};
}
