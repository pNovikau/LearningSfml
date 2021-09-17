#pragma once

#include "string"
#include "Event.h"

namespace engine
{
    class AnimationEndEvent : public Event<AnimationEndEvent>
    {
    public:
        std::string entityId;
    };
}