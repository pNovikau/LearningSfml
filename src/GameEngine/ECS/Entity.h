#pragma once

#include <vector>
#include <memory>
#include <bitset>
#include <GameContext.h>

#include "Components/Component.h"
#include "Helper.h"

namespace engine
{
    class Entity
    {
    public:
        Entity() : _id(Helper::generateRandomString()) { };
        explicit Entity(std::string& id) : _id(id) { };

        virtual void init(const std::unique_ptr<GameContext>& context) = 0;

        template <class TComponent>
        bool hasComponent()
        {
            TComponent component;

            return _componentsMask.test(component.type);
        }

        template<class TComponent1, class TComponent2, class ... TOther>
        bool hasComponents()
        {
            TComponent1 component;

            return _componentsMask.test(component.type) && hasComponents<TComponent2, TOther...>();
        }

        template<class TComponent>
        void removeComponent()
        {
            TComponent component;

            for (int i = 0; i < _components.size(); ++i)
            {
                if (component.type != _components[i]->type)
                    continue;

                _componentsMask.set(component.type, false);
                _components.erase(_components.begin() + i);

                return;
            }
        }

        template<class TComponent>
        std::shared_ptr<TComponent> addOrGetComponent()
        {
            TComponent component;

            for (auto & curComponent : _components)
            {
                if (component.type != curComponent->type)
                    continue;

                return std::static_pointer_cast<TComponent>(curComponent);
            }

            _componentsMask.set(component.type);

            std::shared_ptr<Component> componentPtr;
            componentPtr.reset(new TComponent());
            _components.push_back(componentPtr);

            return std::static_pointer_cast<TComponent>(_components.back());
        }

        template<class TComponent>
        std::shared_ptr<TComponent> tryGetComponent()
        {
            TComponent component;

            for (auto & curComponent : _components)
            {
                if (component.type != curComponent->type)
                    continue;

                return std::static_pointer_cast<TComponent>(curComponent);
            }

            return nullptr;
        }

        std::string getId() { return _id; }

    private:
        std::string _id;
        std::vector<std::shared_ptr<Component>> _components;
        std::bitset<128> _componentsMask;

        template<class TComponent>
        bool hasComponents()
        {
            return hasComponent<TComponent>();
        }
    };
}