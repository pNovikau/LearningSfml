#pragma once

namespace engine
{
    class BaseEvent
    {
    protected:
        static size_t getNextType()
        {
            static size_t typeCount = 0;

            return typeCount++;
        }
    };

    template <class TEventType>
    class Event : public BaseEvent
    {
    public:
        static size_t type()
        {
            static size_t type = getNextType();

            return type;
        }
    };
}