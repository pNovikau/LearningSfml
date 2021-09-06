#pragma once

#include <cstdlib>
#include "GameTime.h"

#include <SFML/System/Clock.hpp>

namespace Utility
{
    /// @brief class for measuring FPS
    class FPS
    {
    public:
        FPS(std::shared_ptr<engine::GameTime> time)
        {
            _time = std::move(time);
        }

        /// @brief Get  current FPS count.
        const std::uint8_t getFPS() const
        {
            return 1.f / _time->get_delta().asSeconds();
        }

    private:
        std::shared_ptr<engine::GameTime> _time;
    };
} //namespace Utility
