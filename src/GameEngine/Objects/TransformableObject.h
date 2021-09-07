#pragma once

#include "GameObject.h"

namespace engine
{
    class TransformableObject : public GameObject
    {
        using GameObject::GameObject;
    public:

        const sf::Vector2f& getPosition() const { return _transformable->getPosition(); }

    protected:
        std::shared_ptr<sf::Transformable> _transformable;

        void move(const sf::Vector2f &offset) { _transformable->move(offset); }
        int getType() override { return static_cast<int>(GameObjectType::transformableObject); }
    };
}