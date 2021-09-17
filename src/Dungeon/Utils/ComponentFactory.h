#pragma once

#include <memory>

#include "AnimationComponent.h"

namespace dungeon::utils
{
    struct ComponentFactory
    {
        static void PopulateAnimationComponent(
                std::shared_ptr<engine::AnimationComponent>& animationComponent,
                std::shared_ptr<sf::Texture>& texture,
                int frames)
        {
            const auto offset = texture->getSize().x / frames;

            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setTextureRect(sf::IntRect(0, 0, offset, texture->getSize().y));

            const auto& localBounds = sprite.getLocalBounds();
            sprite.setOrigin(localBounds.width / 2, 0);

            animationComponent->sprite = std::make_shared<sf::Sprite>(sprite);
            animationComponent->totalFrames = frames;
            animationComponent->timeDelay = 0.1;
            animationComponent->offset = offset;
        }
    };
}