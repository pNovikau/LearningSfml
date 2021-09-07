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

	void GameObject::draw(const std::unique_ptr<GameContext>& context) const
	{
		context->window->draw(*_drawable);
	}
	
	GameObjectType GameObject::getType() const
	{
		return GameObjectType::game_object;
	}


	std::string GameObject::getId() const
	{
		return _id;
	}

	const sf::Vector2f& GameObject::getPosition() const
	{
		return _transformable->getPosition();
	}

	std::shared_ptr<std::set<std::string>> GameObject::getTags() const
	{
		return _tags;
	}

	void GameObject::addTag(const std::string tag) const
	{
		_tags->insert(tag);
	}
}
