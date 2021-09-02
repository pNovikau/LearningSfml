#pragma once
#include <random>

#include "GameObject.h"

namespace game
{
	class Ball : public engine::GameObject
	{
	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override;
		void updated(const std::unique_ptr<engine::GameContext>& context) override;

	private:
		int angle;
	};
}
