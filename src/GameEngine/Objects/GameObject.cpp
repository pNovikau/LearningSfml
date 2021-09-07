#include "GameObject.h"
#include "Utils/Helper.h"

namespace engine
{
	GameObject::GameObject()
	{
        _id = utils::Helper::generate_random_string();
        _tags = std::make_shared<std::set<std::string>>();
	}

	GameObject::GameObject(const std::string& id)
	{
        _id = id;
        _tags = std::make_shared<std::set<std::string>>();
	}

	std::string GameObject::getId() const
	{
		return _id;
	}

	std::shared_ptr<std::set<std::string>> GameObject::getTags() const
	{
		return _tags;
	}

	void GameObject::addTag(const std::string tag) const
	{
		_tags->insert(tag);
	}

    bool GameObject::isType(GameObjectType type)
    {
        return (getType() & static_cast<int>(type)) == static_cast<int>(type);
    }
}
