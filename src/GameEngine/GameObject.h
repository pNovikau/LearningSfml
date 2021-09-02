#pragma once
#include "SFML/Graphics.hpp"
#include "GameContext.h"

namespace engine
{
	class GameObject
	{
	public:
		GameObject();
		explicit GameObject(const std::string& id);

		virtual void init() = 0;

		/// <summary>
		/// Is called once per frame
		/// </summary>
		virtual void updated(std::unique_ptr<GameContext>& context) = 0;

		virtual void handle_event(const sf::Event& event) = 0;

		std::string get_id() const;

	protected:
		//TODO: add a texture
		std::string id_;

		//TODO: use template here
		std::shared_ptr<sf::Drawable> drawable_;
		std::shared_ptr<sf::Transformable> transformable_;
	};
}
