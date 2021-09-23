#pragma once

#include "functional"
#include "vector"

#include "Event.h"

namespace engine
{
    template <class TEventType>
    struct CallbackWrapper
    {
        explicit CallbackWrapper(std::function<void(const TEventType&)> callable) : _callable(callable) {}

        void operator() (const BaseEvent& event)
        {
            _callable(static_cast<const TEventType&>(event));
        }

    private:
        std::function<void(const TEventType&)> _callable;
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
        void subscribe(std::function<void(const TEventType&)> callback)
        {
            _subscribers.push_back(CallbackWrapper<TEventType>(callback));
        }

        std::vector<std::function<void(const BaseEvent&)>> listSubscribers() const
        {
            return _subscribers;
        }

    private:
        std::vector<std::unique_ptr<BaseEvent>> _events;
        std::vector<std::function<void(const BaseEvent&)>> _subscribers;
    };
}