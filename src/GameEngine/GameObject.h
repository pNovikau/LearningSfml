#pragma once
#include <set>

#include "CollisionContext.h"
#include "SFML/Graphics.hpp"
#include "GameContext.h"
#include "GameObjectType.h"

namespace engine
{
	class GameObject
	{
	public:
		GameObject();
		explicit GameObject(const std::string& id);

		virtual void init(const std::unique_ptr<GameContext>& context) = 0;
		virtual void updated(const std::unique_ptr<GameContext>& context) = 0;

		virtual void draw(const std::unique_ptr<GameContext>& context) const;
		virtual GameObjectType get_type() const;

		std::string get_id() const;
		const sf::Vector2f& get_position() const;
		std::shared_ptr<std::set<std::string>> get_tags() const;

		void add_tag(const std::string tag) const;

	protected:
		std::string id_;
		
		std::shared_ptr<sf::Drawable> drawable_;
		std::shared_ptr<sf::Transformable> transformable_;

	private:
		std::shared_ptr<std::set<std::string>> tags_;
	};
}
