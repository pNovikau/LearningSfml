#pragma once

namespace engine
{
    template<typename TEvent>
    class IEventHandler
    {
    public:
        virtual void handleEvent(const TEvent& event) = 0;
    };
}