#pragma once

#include <vector>
#include <memory>
#include <GameContext.h>
#include <set>

#include "Components/Component.h"
#include "Helper.h"

namespace engine
{
    class Entity
    {
    public:
	    virtual ~Entity() = default;
	    Entity();
        explicit Entity(std::string& id);

        virtual void init(const std::unique_ptr<GameContext>& context) = 0;

        [[nodiscard]] std::string getId() const;

        void addTag(const std::string& tag);

        [[nodiscard]] bool hasTag(const std::string& tag) const;

        template <class TComponent>
        [[nodiscard]] bool hasComponent() const
        {
            return _components[getIndex<TComponent>()] != nullptr;
        }

        template<class TComponent, class TSecondComponent, class ... TOther>
        [[nodiscard]] bool hasComponents() const
        {
            return hasComponent<TComponent>() && hasComponents<TSecondComponent, TOther...>();
        }

        template<class TComponent>
        void removeComponent()
        {
            _components.erase(_components.begin() + getIndex<TComponent>());
        }

        template<class TComponent>
        std::shared_ptr<TComponent> addComponent()
        {
            std::shared_ptr<BaseComponent> componentPtr;
            componentPtr.reset(new TComponent());
            _components[getIndex<TComponent>()] = componentPtr;

            return std::static_pointer_cast<TComponent>(_components[getIndex<TComponent>()]);
        }

        template<class TComponent>
        std::shared_ptr<TComponent> tryGetComponent()
        {
            return std::static_pointer_cast<TComponent>(_components[getIndex<TComponent>()]);
        }

    private:
        std::string _id;
        std::set<std::string> _tags;
        std::vector<std::shared_ptr<BaseComponent>> _components;

        template<class TComponent>
        [[nodiscard]] bool hasComponents() const
        {
            return hasComponent<TComponent>();
        }

        template<class TComponent>
        constexpr static size_t getIndex()
        {
            TComponent component;

            return component.getType();
        }
    };
}