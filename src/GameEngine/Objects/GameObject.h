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

        virtual bool isType(GameObjectType type);
		virtual void init(const std::unique_ptr<GameContext>& context) = 0;
		virtual void updated(const std::unique_ptr<GameContext>& context) = 0;

		std::string getId() const;
		std::shared_ptr<std::set<std::string>> getTags() const;

		void addTag(const std::string tag) const;

	protected:
		std::string _id;

        virtual int getType() = 0;
	private:
		std::shared_ptr<std::set<std::string>> _tags;
	};
}
