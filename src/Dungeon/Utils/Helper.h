#pragma once

#include <random>
#include <iomanip>

namespace dungeon::utils
{
    struct Helper
    {
        template<typename T>
        static T randReal(T min, T max)
        {
            std::random_device rd;
            std::default_random_engine eng(rd());
            std::uniform_real_distribution<T> distr(min, max);

            return distr(eng);
        }

        template<typename T>
        static T randInt(T min, T max)
        {
            std::random_device rd;
            std::default_random_engine eng(rd());
            std::uniform_int_distribution<T> distr(min, max);

            return distr(eng);
        }
    };
}