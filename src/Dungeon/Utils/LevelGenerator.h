#pragma once

#include <vector>

#include <SFML/Graphics/Rect.hpp>

namespace dungeon::utils
{
    struct Level
    {
        std::vector<sf::FloatRect> floors;
    };

    struct LevelGenerator
    {
        static Level getLevel()
        {
            Level level;
            level.floors = std::vector<sf::FloatRect>
            {
                {48, 48, 320, 320},
                {368, 208, 160, 160},
            };

            return level;
        }
    };
}