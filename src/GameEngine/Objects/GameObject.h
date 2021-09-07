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
		virtual GameObjectType getType() const;

		std::string getId() const;
		const sf::Vector2f& getPosition() const;
		std::shared_ptr<std::set<std::string>> getTags() const;

		void addTag(const std::string tag) const;

	protected:
		std::string _id;
		
		std::shared_ptr<sf::Drawable> _drawable;
		std::shared_ptr<sf::Transformable> _transformable;

	private:
		std::shared_ptr<std::set<std::string>> _tags;
	};
}
