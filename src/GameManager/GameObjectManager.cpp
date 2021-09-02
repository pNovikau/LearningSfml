#include "GameObjectManager.h"

namespace engine
{
	void GameObjectManager::add(GameObject& game_object)
	{
		std::pair<std::string, std::shared_ptr<GameObject>> pair;

		pair.first = game_object.get_id();
		pair.second = std::make_shared<GameObject>(game_object);

		object_map_.insert(pair);
	}

	void GameObjectManager::remove(const std::string& id)
	{
		object_map_.erase(id);
	}

	void GameObjectManager::remove(const GameObject& game_object)
	{
		const std::string id = game_object.get_id();

		object_map_.erase(id);
	}

	std::shared_ptr<GameObject> GameObjectManager::get(const std::string& id) const
	{
		const auto pair = object_map_.find(id);

		return pair->second;
	}

	std::vector<std::shared_ptr<GameObject>> GameObjectManager::list() const
	{
		//TODO:
	}

}
