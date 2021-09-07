#pragma once
#include "GameObject.h"

namespace engine
{
	class CollidingObject : public GameObject
	{
        using GameObject::GameObject;
	public:

		void init(const std::unique_ptr<GameContext>& context) override;
		void updated(const std::unique_ptr<GameContext>& context) override;

		virtual void collision(const std::unique_ptr<CollisionContext>& context);
		virtual bool contains(const std::shared_ptr<CollidingObject>& object, sf::FloatRect& overlap) const;
		virtual void inspectsCollision(const std::vector<std::shared_ptr<GameObject>>& vector);
		sf::FloatRect getBoundingBox() const;
#ifndef NDEBUG
		void drawCollisionBox(const std::unique_ptr<GameContext>& context) const;
#endif // !NDEBUG

	protected:
		std::shared_ptr<sf::Shape> _shape;

        int getType() override;
	};
}
