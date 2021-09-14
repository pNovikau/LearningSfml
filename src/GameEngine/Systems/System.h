#pragma once

#include "Managers/EntityManager.h"
#include "Managers/EventManager.h"
#include "GameContext.h"

namespace engine
{
    class System
    {
    public:
        System(std::shared_ptr<EntityManager> entityManager, std::shared_ptr<EventManager> eventManager) :
            _entityManager(std::move(entityManager)),
            _eventManager(std::move(eventManager)) {}

        virtual void init(const std::unique_ptr<GameContext>& context) { }

        virtual void update(const std::unique_ptr<GameContext>& context) = 0;

    protected:
        std::shared_ptr<EntityManager> _entityManager;
        std::shared_ptr<EventManager> _eventManager;
    };
}
