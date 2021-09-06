#pragma once

#include <SFML/System/Clock.hpp>
#include <Time.h>

namespace engine
{
    class GameTime
    {
    public:
        GameTime() = default;

        void update()
        {
            ++total_frames_;
            delta_time_ = delta_clock_.restart();
        }

        const int get_total_frames() const
        {
            return total_frames_;
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
        int total_frames_;
        sf::Clock clock_;
        sf::Clock delta_clock_;
        sf::Time delta_time_;
    };
}