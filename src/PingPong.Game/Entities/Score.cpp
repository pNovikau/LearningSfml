#include "Score.h"

#include <iostream>

namespace game
{
	void Score::init(const std::unique_ptr<engine::GameContext>& context)
	{
		//TODO: add font
		sf::Font font;
		
		const auto text = std::make_shared<sf::Text>();
		text->setString("0 : 0");
		text->setPosition(100, 100);
		text->setCharacterSize(24);
		text->setStyle(sf::Text::Bold);
		text->setFillColor(sf::Color::White);

		text_ = text;
		drawable_ = text;
		transformable_ = text;
	}

	void Score::updated(const std::unique_ptr<engine::GameContext>& context)
	{
		text_->setString(std::to_string(player_score_) + " : " + std::to_string(enemy_score_));
	}

	void Score::increment_enemy_score()
	{
		++enemy_score_;

		std::cout
			<< "[" + get_id() + "] score updated "
			<< std::to_string(player_score_) + " : " + std::to_string(enemy_score_)
			<< "\n";
	}

	void Score::increment_player_score()
	{
		++player_score_;

		std::cout
			<< "[" + get_id() + "] score updated "
			<< std::to_string(player_score_) + " : " + std::to_string(enemy_score_)
			<< "\n";
	}
}
