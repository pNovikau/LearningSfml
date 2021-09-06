#pragma once

#include <SFML/System/Clock.hpp>
#include <time.h>

namespace engine
{
    class Time
    {
    public:
        Time() = default;

        void update()
        {
            ++total_frames_;
            delta_time_ = delta_clock_.restart();
        }

        const sf::Time get_time() const
        {
            return clock_.getElapsedTime();
        }

        const sf::Time get_delta() const
        {
            return delta_time_;
        }

    private:
        sf::Clock clock_;
        int total_frames_;
        sf::Clock delta_clock_;
        sf::Time delta_time_;
    };
}