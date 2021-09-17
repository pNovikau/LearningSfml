#include "Floor.h"

#include "DrawComponent.h"

namespace dungeon::entities
{
    void Floor::init(const std::unique_ptr<engine::GameContext> &context)
    {
        auto texture = context->resourceManager->getTexture(floorTextureKey);
        texture->setRepeated(true);

        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect({ 0, 0, static_cast<int>(_position.width), static_cast<int>(_position.height) });
        sprite.setPosition(_position.left, _position.top);

        auto drawComponent = addComponent<engine::DrawComponent>();
        drawComponent->drawable = std::make_shared<sf::Sprite>(sprite);
    }
}