#include "BidZombie.h"

#include "DrawComponent.h"
#include "AnimationComponent.h"
#include "TransformComponent.h"

#include "Utils/ComponentFactory.h"
#include "AnimationStateComponent.h"
#include "EnemyStateComponent.h"
#include "MoveComponent.h"
#include "HealthComponent.h"

namespace dungeon::entities
{
    void BidZombie::init(const std::unique_ptr<engine::GameContext> &context)
    {
        auto animationStateComponent = this->addComponent<dungeon::components::AnimationStateComponent>();
        animationStateComponent->runTexture = context->resourceManager->getTexture(runTextureKey);
        animationStateComponent->idleTexture = context->resourceManager->getTexture(idleTextureKey);

        auto animationComponent = this->addComponent<engine::AnimationComponent>();
        dungeon::utils::ComponentFactory::PopulateAnimationComponent(animationComponent, animationStateComponent->idleTexture, idleTextureFrames);

        auto drawComponent = addComponent<engine::DrawComponent>();
        drawComponent->drawable = animationComponent->sprite;

        auto transformableComponent = addComponent<engine::TransformComponent>();
        transformableComponent->transformable = animationComponent->sprite;
        transformableComponent->speed = 10.f;
        transformableComponent->transformable->setPosition({150, 100});

        addComponent<components::MoveComponent>();
        addComponent<dungeon::components::EnemyStateComponent>();
        addComponent<components::HealthComponent>();

        auto healthComponent = addComponent<components::HealthComponent>();
        healthComponent->health = 3;
    }
}