#pragma once
#include "GameObject.h"

namespace engine
{
	class CollidingGameObject : public GameObject
	{
		using GameObject::GameObject;

	public:

		void init(const std::unique_ptr<GameContext>& context) override;
		void updated(const std::unique_ptr<GameContext>& context) override;

		virtual void collision(const std::unique_ptr<CollisionContext>& context) = 0;
		virtual bool contains(const std::shared_ptr<CollidingGameObject>& object) const;
		virtual void inspects_collision(const std::vector<std::shared_ptr<GameObject>>& vector);
		GameObjectType get_type() const override;
		sf::FloatRect get_bounding_box() const;

#ifndef NDEBUG
		void draw_collision_box(const std::unique_ptr<GameContext>& context) const;
#endif // !NDEBUG

	protected:
		std::shared_ptr<sf::Shape> shape_;
	};
}
