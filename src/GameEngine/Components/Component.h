#pragma once

namespace engine
{
    class BaseComponent
    {
    protected:
        static size_t getNextType()
        {
            static size_t typeCount = 0;

            return typeCount++;
        }
    };

    template<class TComponentType>
    class Component : public BaseComponent
    {
    public:
        static size_t getType()
        {
            static size_t type = getNextType();

            return type;
        }
    };
}