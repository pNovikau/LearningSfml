#pragma once
#include <random>

#include "Objects/TransformableObject.h"
#include "Objects/CollidingObject.h"
#include "Objects/DrawableObject.h"
#include "ScoreManager.h"
#include "Utils/VectorMath.h"

namespace game
{
	class Ball :
            public engine::CollidingObject,
            public engine::DrawableObject
	{
		using CollidingObject::CollidingObject;

	public:
		
		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;
		void collision(const std::unique_ptr<engine::CollisionContext>& context) override;

	private:
		const float radius_ = 10.0f;
		sf::Vector2f velocity_ = Utility::normalise({ -0.5f, 0.1f });
		const float speed_ = 100.f;

		void resolve(const sf::Vector3f& manifold);
	};
}
