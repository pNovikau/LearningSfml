#pragma once

#include "GameObject.h"
#include "TransformableObject.h"

namespace engine
{
    class DrawableObject : public TransformableObject
    {
        using TransformableObject::TransformableObject;
    public:
        void init(const std::unique_ptr<GameContext> &context) override = 0;

        virtual void draw(const std::unique_ptr<GameContext>& context) const
        {
            if (!_drawable || !_isVisible)
                return;

            context->window->draw(*_drawable);
        }

        void Hide() { _isVisible = false; }
        void Show() { _isVisible = true; }

    protected:
        std::shared_ptr<sf::Drawable> _drawable;

        int getType() override
        {
            return TransformableObject::getType() & static_cast<int>(GameObjectType::drawableObject);
        }

    private:
        bool _isVisible;
    };
}
