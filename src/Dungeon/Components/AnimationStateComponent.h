#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "Component.h"

namespace dungeon::components
{
    struct AnimationStateComponent : public engine::Component<AnimationStateComponent>
	{
        std::shared_ptr<sf::Texture> runTexture;
		std::shared_ptr<sf::Texture> idleTexture;
	};
}