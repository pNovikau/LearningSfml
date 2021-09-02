#include "Ball.h"

namespace game
{
	void Ball::init(const std::unique_ptr<engine::GameContext>& context)
	{
		const auto shape = std::make_shared<sf::CircleShape>(20.0f);
		shape->setFillColor(sf::Color::Green);

		drawable_ = shape;
		transformable_ = shape;

		const sf::Vector2u window_size = context->window->getSize();
		transformable_->setPosition(window_size.x / 2.0f, window_size.y / 2.0f);

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		const std::uniform_int_distribution uni(0, 360); // guaranteed unbiased

		angle = uni(rng);
	}

	void Ball::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		auto& position = transformable_->getPosition();

		transformable_->setPosition(position.x + (sin(angle) * 0.1), position.y + (cos(angle) * 0.1));

		context->window->draw(*drawable_);
	}
}