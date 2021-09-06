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

        /// @brief Get current FPS count.
        const std::uint8_t getFPS()
        {
            if (_clock.getElapsedTime().asSeconds() >= 1.0f)
            {
                auto total_frames = _time->get_total_frames();
                
                _fps = _last_total_frames - total_frames;
                _last_total_frames = total_frames;

                _clock.restart();
            }

            return _fps;
        }

    private:
        std::shared_ptr<engine::GameTime> _time;
        int _last_total_frames;
        std::uint8_t _fps;
        sf::Clock _clock;
    };
} //namespace Utility
