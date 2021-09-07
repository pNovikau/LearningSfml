#include "GameObjectManager.h"
#include <ranges>
#include "Utils/Helper.h"

namespace engine
{
	void GameObjectManager::add(const std::shared_ptr<GameObject>& game_object)
	{
		object_map_.emplace(game_object->getId(), game_object);
	}

	void GameObjectManager::remove(const std::string& id)
	{
		object_map_.erase(id);
	}

	void GameObjectManager::remove(const GameObject& game_object)
	{
		object_map_.erase(game_object.getId());
	}

	std::shared_ptr<GameObject> GameObjectManager::get(const std::string& id) const
	{
		const auto pair = object_map_.find(id);

		return pair->second;
	}

	std::vector<std::shared_ptr<GameObject>> GameObjectManager::list() const
	{
		std::vector<std::shared_ptr<GameObject>> objects;

		for (const auto& value : object_map_ | std::views::values)
		{
			objects.push_back(value);
		}

		return objects;
	}
}
