#pragma once

namespace engine
{
    enum class ComponentType
    {
        None        = (1u << 0),
        Transform   = (1u << 1),
        Draw        = (1u << 2),
        Input       = (1u << 3),
        Collision   = (1u << 4)
    };
}