#pragma once

#if !NDEBUG
#include "iostream"
#endif

#include <vector>
#include <memory>
#include <bitset>
#include <GameContext.h>
#include <set>

#include "Components/Component.h"
#include "Helper.h"

namespace engine
{
    class Entity
    {
    public:
        Entity() : _id(Helper::generateRandomString()), _components(128) { }
        explicit Entity(std::string& id) : _id(id), _components(128) { }

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

            _componentsMask.set(component.type, false);
            _components.erase(_components.begin() + getComponentIndex(component.type));
        }

        template<class TComponent>
        std::shared_ptr<TComponent> addOrGetComponent()
        {
            TComponent component;

            if (!_componentsMask.test(component.type))
            {
                _componentsMask.set(component.type);
                addComponent<TComponent>(component.type);
            }

            return getComponent<TComponent>(component.type);
        }

        template<class TComponent>
        std::shared_ptr<TComponent> tryGetComponent()
        {
            TComponent component;

            return _componentsMask.test(component.type)
                ? getComponent<TComponent>(component.type)
                : nullptr;
        }

        std::string getId() { return _id; }

        void addTag(const std::string& tag) { _tags.erase(tag); }

        bool hasTag(const std::string& tag) { return _tags.contains(tag); }

    private:
        std::string _id;
        std::set<std::string> _tags;
        std::vector<std::shared_ptr<Component>> _components;
        std::bitset<128> _componentsMask;

        template<class TComponent>
        bool hasComponents()
        {
            return hasComponent<TComponent>();
        }

        template<class TComponent>
        void addComponent(const int componentType)
        {
            const auto index = getComponentIndex(componentType);

            std::shared_ptr<Component> componentPtr;
            componentPtr.reset(new TComponent());
            _components[index] = componentPtr;

#if !NDEBUG
            std::cout << "[" + getId() + "] component added. (component type: " + std::to_string(componentType) + ")" << std::endl;
#endif
        }

        template<class TComponent>
        std::shared_ptr<TComponent> getComponent(const int componentType)
        {
            const auto index = getComponentIndex(componentType);

            return std::static_pointer_cast<TComponent>(_components[index]);
        }

        static constexpr int isPowerOfTwo(const unsigned componentType)
        {
            return componentType && (!(componentType & (componentType - 1)));
        }

        static int getComponentIndex(const int componentType)
        {
            if (!isPowerOfTwo(static_cast<unsigned>(componentType)))
                return -1;

            int tmp = 1;
            int position = 1;

            while (!(tmp & componentType)) {
                tmp = tmp << 1;

                ++position;
            }

            return --position;
        }
    };
}