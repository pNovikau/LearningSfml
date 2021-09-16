#pragma once

#include "System.h"
#include "AnimationComponent.h"
#include "DrawComponent.h"

namespace engine
{
    class AnimationSystem : public System
    {

        void update(const std::unique_ptr<GameContext> &context) override
        {
            auto entities = _entityManager->listEntitiesByComponents<AnimationComponent, DrawComponent>();

            for (const auto& entity : entities)
            {
                auto animationComponent = entity->tryGetComponent<AnimationComponent>();
                animationComponent->currentDelay += context->time->getDelta().asSeconds();

                if (animationComponent->currentDelay >= animationComponent->timeDelay)
                {
                    auto currentFrame = animationComponent->currentFrame;
                    animationComponent->currentDelay = 0;
                    animationComponent->currentFrame = ++currentFrame % animationComponent->totalFrames;
                }

                const auto& texture = animationComponent->sprite->getTexture();
                animationComponent->sprite->setTextureRect(sf::IntRect(
                        animationComponent->currentFrame * animationComponent->offset,
                        0,
                        animationComponent->offset,
                        texture->getSize().y));
            }
        }
    };
}