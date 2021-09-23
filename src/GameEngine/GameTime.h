#pragma once

#include <SFML/System/Clock.hpp>

namespace engine
{
    class GameTime
    {
    public:
        GameTime() = default;

        void update()
        {
            ++_totalFrames;
            _deltaTime = _deltaClock.restart();
        }

        const int getTotalFrames() const
        {
            return _totalFrames;
        }

        const sf::Time getTime() const
        {
            return _clock.getElapsedTime();
        }

        const sf::Time getDelta() const
        {
            return _deltaTime;
        }

    private:
        int _totalFrames;
        sf::Clock _clock;
        sf::Clock _deltaClock;
        sf::Time _deltaTime;
    };
}