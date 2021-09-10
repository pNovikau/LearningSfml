#pragma once

#include "memory"

namespace engine
{
    template<typename TEvent>
    class IEventHandler
    {
    public:
        virtual void handleEvent(std::unique_ptr<TEvent> event) = 0;
    };
}