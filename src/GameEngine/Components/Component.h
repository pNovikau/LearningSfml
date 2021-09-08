#pragma once

#include "Components/ComponentType.h"

namespace engine
{
    class Component
    {
    public:
        int type = static_cast<int>(ComponentType::None);
    };
}