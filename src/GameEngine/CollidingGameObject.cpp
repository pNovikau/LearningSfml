#include "CollidingGameObject.h"

namespace engine
{
	void CollidingGameObject::collision(const std::unique_ptr<CollisionContext>& context)
	{ }

	void CollidingGameObject::init(const std::unique_ptr<GameContext>& context)
	{ }

	void CollidingGameObject::updated(const std::unique_ptr<GameContext>& context)
	{ }

	void CollidingGameObject::draw_collision_box(const std::unique_ptr<GameContext>& context) const
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

	bool CollidingGameObject::contains(const std::shared_ptr<CollidingGameObject>& object) const
	{
		return get_bounding_box().intersects(object->get_bounding_box());
	}

	void CollidingGameObject::inspects_collision(const std::vector<std::shared_ptr<GameObject>>& vector)
	{
		for (auto& game_object : vector)
		{
			if (game_object->get_type() != colliding_game_object)
				continue;

			auto colliding_game_object = std::static_pointer_cast<CollidingGameObject>(game_object);

			if (game_object->get_id() != this->get_id() && contains(colliding_game_object))
			{
				CollisionContext context;
				context.game_object = game_object;

				collision(std::make_unique<CollisionContext>(context));
			}
		}
	}

	GameObjectType CollidingGameObject::get_type() const
	{
		return colliding_game_object;
	}

	sf::FloatRect CollidingGameObject::get_bounding_box() const
	{
		return shape_->getGlobalBounds();
	}
}