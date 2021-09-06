#pragma once

#include <cmath>

#include <SFML/System.hpp>

namespace Utility
{

    inline float dot(const sf::Vector2f& left, const sf::Vector2f& right)
    {
        return left.x * right.x + left.y * right.y;
    }

    inline sf::Vector2f normalise(sf::Vector2f input)
    {
        float length = std::sqrt(dot(input, input));
        if (length != 0)
            input /= length;

        return input;
    }

    inline sf::Vector2f reflect(const sf::Vector2f& velocity, const sf::Vector2f& normal)
    {
        return -2.f * dot(velocity, normal) * normal + velocity;
    }

    inline float squareLength(const sf::Vector2f& input)
    {
        return dot(input, input);
    }
    inline sf::Vector3f getManifold(const sf::FloatRect& overlap, const sf::Vector2f& collisionNormal)
    {
        // z is for penetration
        sf::Vector3f manifold;

        if (overlap.width < overlap.height)
        {
            manifold.x = (collisionNormal.x < 0) ? 1.f : -1.f;
            manifold.z = overlap.width;
        }
        else
        {
            manifold.y = (collisionNormal.y < 0) ? 1.f : -1.f;
            manifold.z = overlap.height;
        }

        return manifold;
    }
} //namespace Utility
