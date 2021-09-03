#include "GameObject.h"
#include "Utils/Helper.h"
#include "CollisionContext.h"

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

	void GameObject::inspects_collision(const std::vector<std::shared_ptr<GameObject>>& vector)
	{
		for (auto& game_object : vector)
		{
			if (game_object->get_id() != this->get_id() && contains(game_object))
			{
				CollisionContext context;
				context.game_object = game_object;
				context.contacts = get_collision_contact_points(game_object);

				collision(std::make_unique<CollisionContext>(context));
			}
		}
	}

	bool GameObject::contains(const std::shared_ptr<GameObject>& object) const
	{
		return get_bounding_box().intersects(object->get_bounding_box());
	}


	std::string GameObject::get_id() const
	{
		return id_;
	}

	const sf::Vector2f& GameObject::get_position() const
	{
		return shape_->getPosition();
	}

	sf::FloatRect GameObject::get_bounding_box() const
	{
		return shape_->getGlobalBounds();
	}

	void GameObject::draw_collision_box(const std::unique_ptr<GameContext>& context) const
	{
		const auto bounding_box = get_bounding_box();

		const sf::Vector2f rectangle_size(bounding_box.width, bounding_box.height);
		auto collision_box = sf::RectangleShape(rectangle_size);
		collision_box.setPosition(bounding_box.left, bounding_box.top);
		collision_box.setOutlineColor(sf::Color::Red);
		collision_box.setFillColor(sf::Color::Transparent);
		collision_box.setOutlineThickness(1);

		context->window->draw(collision_box);
	}

	std::vector<ContactPoint<float>> GameObject::get_collision_contact_points(const std::shared_ptr<GameObject>& object) const
	{
		const auto& self_bounding_box = get_bounding_box();
		const auto& object_bounding_box = object->get_bounding_box();

		sf::FloatRect intercept;

		self_bounding_box.intersects(object_bounding_box, intercept);

		//how da fac I need to calculate the collision normal
		sf::Vector2f normal;

		std::vector<ContactPoint<float>> contact_points;
		//contact_points.emplace_back(intercept.left, intercept.top);
		//contact_points.emplace_back(intercept.left + intercept.width, intercept.top);
		//contact_points.emplace_back(intercept.left, intercept.top + intercept.width);
		//contact_points.emplace_back(intercept.left + intercept.width, intercept.top + intercept.width);

		return contact_points;
	}

}
