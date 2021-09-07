#include "CollidingObject.h"

namespace engine
{
	void CollidingObject::collision(const std::unique_ptr<CollisionContext>& context)
	{ }

	void CollidingObject::init(const std::unique_ptr<GameContext>& context)
	{ }

	void CollidingObject::updated(const std::unique_ptr<GameContext>& context)
	{ }

	bool CollidingObject::contains(const std::shared_ptr<CollidingObject>& object, sf::FloatRect& overlap) const
	{
		return getBoundingBox().intersects(object->getBoundingBox(), overlap);
	}

	void CollidingObject::inspectsCollision(const std::vector<std::shared_ptr<GameObject>>& vector)
	{
		for (auto& game_object : vector)
		{
			if (game_object->isType(GameObjectType::collidingObject))
				continue;

			auto colliding_game_object = std::static_pointer_cast<CollidingObject>(game_object);
			sf::FloatRect overlap;

			if (game_object->getId() != this->getId() && contains(colliding_game_object, overlap))
			{
				CollisionContext context;
				context.game_object = game_object;
				context.overlap = std::move(overlap);

				collision(std::make_unique<CollisionContext>(context));
			}
		}
	}

	sf::FloatRect CollidingObject::getBoundingBox() const
	{
		return _shape->getGlobalBounds();
	}

    int CollidingObject::getType()
    {
        return static_cast<int>(GameObjectType::collidingObject);
    }

#ifndef NDEBUG
	void CollidingObject::drawCollisionBox(const std::unique_ptr<GameContext>& context) const
	{
		const auto bounding_box = getBoundingBox();

		auto collision_box = sf::RectangleShape({ bounding_box.width, bounding_box.height });
		collision_box.setPosition(bounding_box.left, bounding_box.top);
		collision_box.setOutlineColor(sf::Color::Red);
		collision_box.setFillColor(sf::Color::Transparent);
		collision_box.setOutlineThickness(1);

		context->window->draw(collision_box);
	}

#endif // !NDEBUG
}
