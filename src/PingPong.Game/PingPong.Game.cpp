// PingPong.Game.cpp : Defines the entry point for the application.
//

#include <random>

#include "GameManager.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Ball : public engine::GameObject
{
public:
	void handle_event(const sf::Event& event) override
	{}
	
	int angle;
	void init() override
	{
		const auto shape = std::make_shared<sf::CircleShape>(20.0f);
		shape->setFillColor(sf::Color::Green);

		drawable_ = shape;
		transformable_ = shape;

		transformable_->setPosition(600, 600);

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		const std::uniform_int_distribution<int> uni(0, 360); // guaranteed unbiased

		angle = uni(rng);
	}

	
	void updated(std::unique_ptr<engine::GameContext>& context) override
	{
		auto& position = transformable_->getPosition();
		
		transformable_->setPosition(position.x + (sin(angle) * 0.1), position.y + (cos(angle) * 0.1));

		context->window->draw(*drawable_);
	}
};


class Player : public engine::GameObject
{
public:
	void init() override;

	void updated(std::unique_ptr<engine::GameContext>& context) override;

	void handle_event(const sf::Event& event) override;
};

void Player::handle_event(const sf::Event& event)
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


void Player::init()
{
	const auto shape = std::make_shared<sf::CircleShape>(20.0f);
	shape->setFillColor(sf::Color::Green);

	drawable_ = shape;
	transformable_ = shape;
}

void Player::updated(std::unique_ptr<engine::GameContext>& context)
{
	context->window->draw(*drawable_);
}



int main()
{
	const engine::GameManager game_manager(1200, 1200, "yey");

	const auto player = std::make_shared<Player>();
	game_manager.get_object_manager()->add(player);

	for (int i = 0; i < 20; i++)
	{
		const auto ball = std::make_shared<Ball>();

		game_manager.get_object_manager()->add(ball);
	}

	game_manager.init();

	game_manager.start();
	
	//sf::RenderWindow window(sf::VideoMode(200, 200), "yey");
	//
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//
	//while (window.isOpen())
	//{
	//	sf::Event event;
	//
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}
	//
	//	window.clear();
	//	window.draw(shape);
	//	window.display();
	//}

	return 0;
}
