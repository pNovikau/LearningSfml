#pragma once

#include "Constants.h"
#include <Entity.h>
#include <Components/TransformComponent.h>
#include <Components/CollidingComponent.h>
#include "Components/DrawComponent.h"

namespace game
{
	class Wall : public engine::Entity
	{
		using Entity::Entity;

	public:

		void init(const std::unique_ptr<engine::GameContext>& context) override
        {
            const auto shape = std::make_shared<sf::RectangleShape>(size_);
            shape->setFillColor(sf::Color::White);
            shape->setSize(size_);
            shape->setOrigin(origin_);
            shape->setPosition(position_);

            const auto& transformComponent = this->addOrGetComponent<engine::TransformComponent>();
            transformComponent->transformable = shape;

            const auto& collidingComponent = this->addOrGetComponent<engine::CollidingComponent>();
            collidingComponent->globalBounds = shape->getGlobalBounds();
            collidingComponent->localBounds = shape->getLocalBounds();

            const auto& drawComponent = this->addOrGetComponent<engine::DrawComponent>();
            drawComponent->drawable = shape;

            this->addTag(Constants::Tags::WALL);
        }

		void set_size(const sf::Vector2f& size) { size_ = size; }
		void set_position(const sf::Vector2f& position) { position_ = position; }
		void set_origin(const sf::Vector2f& origin) { origin_ = origin; }

	private:
		sf::Vector2f size_;
		sf::Vector2f position_;
		sf::Vector2f origin_;
	};

    class Trigger : public engine::Entity
    {
        using Entity = Entity;

    public:

        void init(const std::unique_ptr<engine::GameContext> &context) override
        {
            const auto shape = std::make_shared<sf::RectangleShape>();
            shape->setSize(size_);
            shape->setPosition(position_);

            const auto& transformComponent = this->addOrGetComponent<engine::TransformComponent>();
            transformComponent->transformable = shape;

            const auto& collidingComponent = this->addOrGetComponent<engine::CollidingComponent>();
            collidingComponent->globalBounds = shape->getGlobalBounds();
            collidingComponent->localBounds = shape->getLocalBounds();

            this->addTag(Constants::Tags::TRIGGER);
        }

        void set_size(const sf::Vector2f& size) { size_ = size; }
        void set_position(const sf::Vector2f& position) { position_ = position; }

    private:
        sf::Vector2f size_;
        sf::Vector2f position_;
    };
}
