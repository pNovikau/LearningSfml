#include "GameObject.h"
#include "Utils/Helper.h"

namespace engine
{
	GameObject::GameObject()
	{
		id_ = Helper::generateRandomString();
		tags_ = std::make_shared<std::set<std::string>>();
	}

	GameObject::GameObject(const std::string& id)
	{
		id_ = id;
		tags_ = std::make_shared<std::set<std::string>>();
	}

	void GameObject::draw(const std::unique_ptr<GameContext>& context) const
	{
		context->window->draw(*drawable_);
	}
	
	GameObjectType GameObject::get_type() const
	{
		return GameObjectType::game_object;
	}


	std::string GameObject::get_id() const
	{
		return id_;
	}

	const sf::Vector2f& GameObject::get_position() const
	{
		return transformable_->getPosition();
	}

	std::shared_ptr<std::set<std::string>> GameObject::get_tags() const
	{
		return tags_;
	}

	void GameObject::add_tag(const std::string tag) const
	{
		tags_->insert(tag);
	}
}
