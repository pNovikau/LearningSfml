#pragma once

#include "Managers/EntityManager.h"
#include "GameContext.h"

namespace engine
{
    class System
    {
    public:
        System(std::shared_ptr<EntityManager> entityManager)
        {
            _entityManager = std::move(entityManager);
        }

        virtual void update(const std::unique_ptr<GameContext>& context) = 0;

    protected:
        std::shared_ptr<EntityManager> _entityManager;
    };
}