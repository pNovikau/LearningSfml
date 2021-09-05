// GameManager.cpp : Source file for your target.
//

#include "GameManager.h"
#include "CollidingGameObject.h"
#include "FPS.h"

namespace engine
{
	GameManager::GameManager(const unsigned int width, const unsigned int height, const std::string& title)
		: title_(title)
	{
		window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title_);
		object_manager_ = std::make_shared<GameObjectManager>();
	}

	void GameManager::init() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = window_;

		for (const auto& game_obj : object_manager_->list())
		{
			game_obj->init(context);
		}
	}

	void GameManager::start() const
	{
		const auto context = std::make_unique<GameContext>();
		context->window = window_;
		Utility::FPS fps;

		while (window_->isOpen())
		{
			sf::Event event{};

			while (window_->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window_->close();
			}

			window_->clear();

			//TODO: optimize 3 loops below
			for (const auto& game_obj : object_manager_->list())
				game_obj->updated(context);

			for (const auto& game_obj : object_manager_->list())
			{
				if (game_obj->get_type() == GameObjectType::colliding_game_object)
					std::static_pointer_cast<CollidingGameObject>(game_obj)->inspects_collision(object_manager_->list());
			}

			for (const auto& game_obj : object_manager_->list())
			{
				game_obj->draw(context);

				if (game_obj->get_type() == GameObjectType::colliding_game_object)
					std::static_pointer_cast<CollidingGameObject>(game_obj)->draw_collision_box(context);
			}
			fps.update();

			auto fpsStr = std::to_string(fps.getFPS());
			window_->setTitle(title_ + " FPS: " + fpsStr);

			window_->display();
		}
	}

	std::shared_ptr<GameObjectManager> GameManager::get_object_manager() const
	{
		return object_manager_;
	}

}