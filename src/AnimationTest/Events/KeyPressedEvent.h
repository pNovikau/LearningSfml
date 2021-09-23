#pragma once

#include "bitset"
#include "Event.h"
#include "SFML/Graphics.hpp"

class KeyPressedEvent : public engine::Event<KeyPressedEvent>
{
public:
    std::bitset<64> keys;
    std::string currentEntityId;
};

