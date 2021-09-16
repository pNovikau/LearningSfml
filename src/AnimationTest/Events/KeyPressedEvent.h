#pragma once

#include "Event.h"
#include "SFML/Graphics.hpp"

class KeyPressedEvent : public engine::Event<KeyPressedEvent>
{
public:
    sf::Keyboard::Key key;
    std::string currentEntityId;
};

