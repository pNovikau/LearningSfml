#include "AnimationStateSystem.h"

#include "AnimationComponent.h"

#include "AnimationStateComponent.h"
#include "EnemyStateComponent.h"
#include "MoveComponent.h"

namespace dungeon::systems
{
    void AnimationStateSystem::init(const std::unique_ptr<engine::GameContext> &context)
    {
        subscribe<events::EnemyStateChanged>();
    }

    void AnimationStateSystem::update(const std::unique_ptr<engine::GameContext> &context)
    { }

    void AnimationStateSystem::handleEvent(const events::EnemyStateChanged &event)
    {
        const auto& entity = _entityManager->getEntity<engine::Entity>(event.entityId);

        const auto& animationStateComponent = entity->tryGetComponent<components::AnimationStateComponent>();
        const auto& animationComponent = entity->tryGetComponent<engine::AnimationComponent>();

        if (event.currentState == EnemyState::Idle && event.currentState != event.prevState)
        {
            const auto& texture = animationStateComponent->idleTexture;

            animationComponent->sprite->setTexture(*texture);
            animationComponent->sprite->setTextureRect(sf::IntRect(0, 0, animationComponent->offset, texture->getSize().y));

            animationComponent->currentDelay = 0;
            animationComponent->currentFrame = 0;
        }
        else if (event.currentState == EnemyState::Walking && event.currentState != event.prevState)
        {
            const auto& texture = animationStateComponent->runTexture;

            animationComponent->sprite->setTexture(*texture);
            animationComponent->sprite->setTextureRect(sf::IntRect(0, 0, animationComponent->offset, texture->getSize().y));

            const auto& moveComponent = entity->tryGetComponent<components::MoveComponent>();

            animationComponent->currentDelay = 0;
            animationComponent->currentFrame = 0;
        }
    }
}