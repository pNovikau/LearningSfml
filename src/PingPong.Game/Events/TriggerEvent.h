#pragma once

#include "Entity.h"
#include "Events/Event.h"

namespace game
{
    class TriggerEvent : public engine::Event<TriggerEvent>
    {
    public:
        std::string triggerEntityId;
        std::string targetEntityId;
    };
}
