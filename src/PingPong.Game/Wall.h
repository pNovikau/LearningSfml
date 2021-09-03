#pragma once
#include "GameObject.h"

namespace game
{
	class Wall : public engine::GameObject
	{
		using GameObject::GameObject;

	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

		void set_size(const sf::Vector2f& size);
		void set_position(const sf::Vector2f& position);

	private:
		sf::Vector2f size_;
		sf::Vector2f position_;
	};
}
