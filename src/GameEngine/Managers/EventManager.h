#pragma once

#include "Events/EventQueue.h"

namespace engine
{
    class EventManager
    {
    public:
        template<class TEventType>
        void subscribe(const std::function<void(std::unique_ptr<TEventType>)> func)
        {
            const size_t type = Event<TEventType>::type();

            if (type >= _queues.size())
                _queues.resize(type + 1);

            _queues[type].subscribe(func);
        }

        template<class TEventType>
        auto addEvent(const TEventType& event) -> void
        {
            const auto type = Event<TEventType>::type();

            if (type >= _queues.size())
            {
                _queues.resize(type + 1);
            }

            _queues[type].enqueue(std::make_unique<TEventType>(event));
        }

        void notifyAll()
        {
            for (auto& queue : _queues)
            {
                while (!queue.isEmpty())
                {
                    auto event = queue.dequeue();

                    for (const auto& callback : queue.listSubscribers())
                    {
                        callback(std::move(event));
                    }
                }
            }
        }

    private:
        std::vector<EventQueue> _queues;
    };
}