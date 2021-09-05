#pragma once

#include <cstdlib>

#include <SFML/System/Clock.hpp>

namespace Utility
{
    /// @brief class for measuring FPS
    class FPS
    {
    public:
        FPS() = default;

        /// @brief Update frame count
        void update()
        {
            if (_clock.getElapsedTime().asSeconds() >= 1.0f)
            {
                _fps = _frame;
                _frame = 0;
                _clock.restart();
            }

            ++_frame;
        }

        /// @brief Get  current FPS count.
        const std::uint8_t getFPS() const
        {
            return _fps;
        }

    private:
        std::uint8_t _frame{0};
        std::uint8_t _fps{0};
        sf::Clock _clock;
    };
} //namespace Utility
