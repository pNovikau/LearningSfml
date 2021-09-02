#include "GameObject.h"
#include "Utils/Helper.h"

namespace engine
{
	GameObject::GameObject()
	{
		id_ = utils::Helper::generate_random_string();
	}

	GameObject::GameObject(const std::string& id)
	{
		id_ = id;
	}
	

	std::string GameObject::get_id() const
	{
		return id_;
	}
}
