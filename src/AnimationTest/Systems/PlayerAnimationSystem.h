#pragma once

#include "set"
#include "unordered_map"

#include "System.h"
#include <Events/IEventHander.h>
#include "AnimationComponent.h"
#include "AnimationEndEvent.h"

#include "Constants.h"
#include "KeyPressedEvent.h"

class PlayerAnimationSystem :
        public engine::System,
        public engine::IEventHandler<KeyPressedEvent>,
        public engine::IEventHandler<engine::AnimationEndEvent>
{
    void init(const std::unique_ptr<engine::GameContext>& context) override;

    void update(const std::unique_ptr<engine::GameContext> &context) override;

    void handleEvent(const KeyPressedEvent& event) override;
    void handleEvent(const engine::AnimationEndEvent& event) override;

    template<typename TEvent>
    void subscribe()
    {
        _eventManager->subscribe<TEvent>([this]<typename TCollisionEvent>(TCollisionEvent && event)
        {
            handleEvent(std::forward<TCollisionEvent>(event));
        });
    }

private:
    const std::string IDLE = "idle";
    const std::string ROLL = "roll";
    const std::string RUN_LEFT = "run_left";
    const std::string RUN_RIGHT = "run_right";

    std::shared_ptr<sf::Texture> _rollTexture;
    uint16_t _rollFrames = 15;

    std::shared_ptr<sf::Texture> _runTexture;
    uint16_t _runFrames = 8;

    std::shared_ptr<sf::Texture> _idleTexture;
    uint16_t _idleFrames = 15;

    std::string _currentState;

    void setIdle(const std::shared_ptr<engine::Entity>& playerEntity);
    void setRunLeft(const std::shared_ptr<engine::Entity>& playerEntity);
    void setRunRight(const std::shared_ptr<engine::Entity>& playerEntity);
    void setRollLeft(const std::shared_ptr<engine::Entity>& playerEntity);
    void setRollRight(const std::shared_ptr<engine::Entity>& playerEntity);

    static void resetAnimationComponent(std::shared_ptr<engine::AnimationComponent>& component, std::shared_ptr<sf::Texture>& texture, uint16_t totalFrames);
};