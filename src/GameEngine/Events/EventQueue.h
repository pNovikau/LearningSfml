#pragma once

#include "functional"
#include "vector"

#include "Event.h"

namespace engine
{
    template <class TEventType>
    struct CallbackWrapper
    {
        explicit CallbackWrapper(std::function<void(std::unique_ptr<TEventType>)> callable) : _callable(callable) {}

        void operator() (std::unique_ptr<BaseEvent> event)
        {
            BaseEvent* eventPtr = event.release();
            auto* tEventTypePtr = static_cast<TEventType*>(eventPtr);
            std::unique_ptr<TEventType> newEvent(tEventTypePtr);

            _callable(std::move(newEvent));
        }

    private:
        std::function<void(std::unique_ptr<TEventType>)> _callable;
    };

    class EventQueue
    {
    public:
        void enqueue(std::unique_ptr<BaseEvent> event)
        {
            _events.emplace_back(std::move(event));
        }

        std::unique_ptr<BaseEvent> dequeue()
        {
            auto& event = _events.back();

            std::unique_ptr<BaseEvent> ptr = std::move(event);
            _events.pop_back();

            return std::move(ptr);
        }

        bool isEmpty() const
        {
            return _events.empty();
        }

        template<class TEventType>
        void subscribe(std::function<void(std::unique_ptr<TEventType>)> callback)
        {
            _subscribers.push_back(CallbackWrapper<TEventType>(callback));
        }

        std::vector<std::function<void(std::unique_ptr<BaseEvent> event)>> listSubscribers() const
        {
            return _subscribers;
        }

    private:
        std::vector<std::unique_ptr<BaseEvent>> _events;
        std::vector<std::function<void(std::unique_ptr<BaseEvent>)>> _subscribers;
    };
}