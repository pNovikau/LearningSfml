#include "GameObject.h"
#include "Utils/Helper.h"
#include <random>

namespace engine
{
	GameObject::GameObject(const std::shared_ptr<sf::RenderWindow>& window)
	{
		window_ = window;
		id_ = Helper::generate_random_string();
	}

	GameObject::GameObject(const std::shared_ptr<sf::RenderWindow>& window, const std::string& id)
	{
		window_ = window;
		id_ = id;
	}

	std::string GameObject::get_id() const
	{
		return id_;
	}
}
