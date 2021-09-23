#include "PlayerAnimationSystem.h"

void PlayerAnimationSystem::init(const std::unique_ptr<engine::GameContext> &context)
{
    _runTexture = _resourceManager->getTexture("player_run");
    _idleTexture = _resourceManager->getTexture("player_idle");
    _rollTexture = _resourceManager->getTexture("player_roll");

    subscribe<KeyPressedEvent>();
}

void PlayerAnimationSystem::update(const std::unique_ptr<engine::GameContext> &context)
{
    if (_currentState == IDLE ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return;

    auto entity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);
    setIdle(entity);
}

void PlayerAnimationSystem::handleEvent(const KeyPressedEvent &event)
{
    if (event.currentEntityId != Constants::Entities::PLAYER_ID ||
        _currentState == ROLL)
        return;

    auto entity = _entityManager->getEntity<engine::Entity>(Constants::Entities::PLAYER_ID);

    if (event.keys[sf::Keyboard::LShift])
    {
        if (event.keys[sf::Keyboard::A])
        {
            setRollLeft(entity);
            return;
        }

        setRollRight(entity);
        return;
    }

    if (event.keys[sf::Keyboard::A] && _currentState != RUN_LEFT)
        setRunLeft(entity);
    else if (event.keys[sf::Keyboard::D] && _currentState != RUN_RIGHT)
        setRunRight(entity);
}

void PlayerAnimationSystem::handleEvent(const engine::AnimationEndEvent& event)
{

}

void PlayerAnimationSystem::setIdle(const std::shared_ptr<engine::Entity>& playerEntity)
{
    auto animationComponent = playerEntity->tryGetComponent<engine::AnimationComponent>();
    resetAnimationComponent(animationComponent, _idleTexture, _idleFrames);

    _currentState = IDLE;
}

void PlayerAnimationSystem::setRunLeft(const std::shared_ptr<engine::Entity>& playerEntity)
{
    auto animationComponent = playerEntity->tryGetComponent<engine::AnimationComponent>();

    if (_currentState == IDLE)
        resetAnimationComponent(animationComponent, _runTexture, _runFrames);

    animationComponent->sprite->setScale(-1.f, 1.f);
    _currentState = RUN_LEFT;
}

void PlayerAnimationSystem::setRunRight(const std::shared_ptr<engine::Entity>& playerEntity)
{
    auto animationComponent = playerEntity->tryGetComponent<engine::AnimationComponent>();

    if (_currentState == IDLE)
        resetAnimationComponent(animationComponent, _runTexture, _runFrames);

    animationComponent->sprite->setScale(1.f, 1.f);
    _currentState = RUN_RIGHT;
}

void PlayerAnimationSystem::setRollLeft(const std::shared_ptr<engine::Entity>& playerEntity)
{
    auto animationComponent = playerEntity->tryGetComponent<engine::AnimationComponent>();
    resetAnimationComponent(animationComponent, _rollTexture, _rollFrames);
    animationComponent->timeDelay = 0.08f;

    animationComponent->sprite->setScale(-1.f, 1.f);
    _currentState = ROLL;
}

void PlayerAnimationSystem::setRollRight(const std::shared_ptr<engine::Entity>& playerEntity)
{
    auto animationComponent = playerEntity->tryGetComponent<engine::AnimationComponent>();
    resetAnimationComponent(animationComponent, _rollTexture, _rollFrames);
    animationComponent->timeDelay = 0.08f;

    animationComponent->sprite->setScale(1.f, 1.f);
    _currentState = ROLL;
}

void PlayerAnimationSystem::resetAnimationComponent(std::shared_ptr<engine::AnimationComponent>& component,
                                                    std::shared_ptr<sf::Texture>& texture,
                                                    uint16_t totalFrames)
{
    auto size = texture->getSize();
    int height = size.y;
    int offset = size.x / totalFrames;

    component->offset = offset;
    component->currentDelay = 0;
    component->currentFrame = 0;
    component->totalFrames = totalFrames;
    component->sprite->setTexture(*texture);
    component->sprite->setTextureRect({0, 0, offset, height});
}