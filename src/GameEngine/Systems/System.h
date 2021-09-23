#pragma once

#include <utility>

#include "Managers/ResourceManager.h"
#include "Managers/EntityManager.h"
#include "Managers/EventManager.h"
#include "GameContext.h"

namespace engine
{
    class System
    {
    public:
        virtual void init(const std::unique_ptr<GameContext>& context) { }

        virtual void update(const std::unique_ptr<GameContext>& context) = 0;

        void setResourceManager(std::shared_ptr<ResourceManager> resourceManager)
        {
            _resourceManager = std::move(resourceManager);
        }

        void setEntityManager(std::shared_ptr<EntityManager> entityManager)
        {
            _entityManager = std::move(entityManager);
        }

        void setEventManager(std::shared_ptr<EventManager> eventManager)
        {
            _eventManager = std::move(eventManager);
        }

    protected:
        std::shared_ptr<ResourceManager> _resourceManager;
        std::shared_ptr<EntityManager> _entityManager;
        std::shared_ptr<EventManager> _eventManager;
    };
}
