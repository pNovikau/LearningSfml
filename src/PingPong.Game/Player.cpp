#include "Player.h"

namespace game
{
	void Player::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto shape = std::make_shared<sf::CircleShape>(20.0f);
		shape->setFillColor(sf::Color::Green);

		drawable_ = shape;
		transformable_ = shape;
	}

	void Player::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		for (const auto& event : *context->events)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					auto& position = transformable_->getPosition();

					transformable_->setPosition(position.x - 3, position.y);
				}
				else if (event.key.code == sf::Keyboard::D)
				{
					auto& position = transformable_->getPosition();

					transformable_->setPosition(position.x + 3, position.y);
				}
			}
		}

		context->window->draw(*drawable_);
	}
}
