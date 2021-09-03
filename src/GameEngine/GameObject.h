#pragma once
#include "CollisionContext.h"
#include "SFML/Graphics.hpp"
#include "GameContext.h"

namespace engine
{
	class GameObject
	{
	public:
		GameObject();
		explicit GameObject(const std::string& id);

		virtual void init(const std::unique_ptr<GameContext>& context) = 0;
		virtual void updated(const std::unique_ptr<GameContext>& context) = 0;
		virtual void collision(const std::unique_ptr<CollisionContext>& context) = 0;

		bool contains(const std::shared_ptr<GameObject>& object) const;
		void draw_collision_box(const std::unique_ptr<GameContext>& context) const;
		void inspects_collision(const std::vector<std::shared_ptr<GameObject>>& vector);

		std::string get_id() const;
		sf::FloatRect get_bounding_box() const;
		const sf::Vector2f& get_position() const;

	protected:
		//TODO: add a texture
		std::string id_;

		//TODO: use template here
		std::shared_ptr<sf::Shape> shape_;

	private:
		std::vector<ContactPoint<float>> get_collision_contact_points(const std::shared_ptr<GameObject>& object) const;
	};
}
