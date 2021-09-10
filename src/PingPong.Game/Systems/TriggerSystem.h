#pragma once

#include <Constants.h>
#include "Components/CollidingComponent.h"
#include "Components/TransformComponent.h"
#include "Systems/System.h"
#include "Utils/VectorMath.h"

namespace game
{
    class TriggerSystem : public engine::System
    {
    public:
        explicit TriggerSystem(std::shared_ptr<engine::EntityManager> entityManager)
            : System(std::move(entityManager)) {};

        void update(const std::unique_ptr<engine::GameContext> &context) override
        {

        }
    };
}