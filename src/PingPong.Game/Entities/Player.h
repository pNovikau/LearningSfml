#pragma once

#include <ECS/Entity.h>

namespace game
{
	class Player : public engine::Entity
	{
	public:

        explicit Player(std::string id) : Entity(id) { }

        void init(const std::unique_ptr<engine::GameContext> &context) override;

	private:
		const float _speed = 75.f;
	};
}
