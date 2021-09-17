#include "Coin.h"

#include "DrawComponent.h"
#include "AnimationComponent.h"
#include "TransformComponent.h"

#include "Utils/ComponentFactory.h"
#include "AnimationStateComponent.h"

namespace dungeon::entities
{
    void Coin::init(const std::unique_ptr<engine::GameContext> &context)
    {
        auto texture = context->resourceManager->getTexture(textureFrameKey);
        auto animationComponent = this->addComponent<engine::AnimationComponent>();
        dungeon::utils::ComponentFactory::PopulateAnimationComponent(animationComponent, texture, frameCount);

        auto drawComponent = addComponent<engine::DrawComponent>();
        drawComponent->drawable = animationComponent->sprite;

        auto transformableComponent = addComponent<engine::TransformComponent>();
        transformableComponent->transformable = animationComponent->sprite;
        transformableComponent->transformable->setPosition({180, 100});
    }
}