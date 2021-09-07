#pragma once
#include <string>

#include "GameObject.h"

namespace engine
{
	class GameObjectManager
	{
	public:
		void add(const std::shared_ptr<GameObject>& game_object);

		void remove(const std::string& id);
		void remove(const GameObject& game_object);

		std::shared_ptr<GameObject> get(const std::string& id) const;
		std::vector<std::shared_ptr<GameObject>> list() const;

	private:
		std::map<std::string, std::shared_ptr<GameObject>> object_map_;
	};
}
