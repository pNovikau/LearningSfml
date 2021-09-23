#pragma once

#include "Entity.h"

namespace engine
{
    class EntityManager
    {
    public:
        template<class TEntity>
        std::shared_ptr<TEntity> createEntity()
        {
            TEntity entity;

            _entities.push_back(std::make_shared<TEntity>(entity));

            return std::static_pointer_cast<TEntity>(_entities.back());
        }

        template<class TEntity>
        std::shared_ptr<TEntity> addEntity(TEntity entity)
        {
            _entities.push_back(std::make_shared<TEntity>(entity));

            return std::static_pointer_cast<TEntity>(_entities.back());
        }

        void deleteEntity(std::string& id)
        {
            for (int i = 0; i < _entities.size(); ++i)
            {
                if (_entities[i]->getId() != id)
                    continue;

                _entities.erase(_entities.begin() + i);
                return;
            }
        }

        template<class TEntity>
        std::shared_ptr<TEntity> getEntity(const std::string& id)
        {
            for (const auto &entity : _entities)
            {
                if (entity->getId() == id)
                    return std::static_pointer_cast<TEntity>(entity);
            }

            return nullptr;
        }

        template<class TComponent>
        std::vector<std::shared_ptr<Entity>> listEntitiesByComponent()
        {
            std::vector<std::shared_ptr<Entity>> result;

            for (const auto &entity : _entities)
            {
                if (entity->hasComponent<TComponent>())
                {
                    result.push_back(entity);
                }
            }

            return result;
        }

        template<class TComponent, class ... TOther>
        std::vector<std::shared_ptr<Entity>> listEntitiesByComponents()
        {
            std::vector<std::shared_ptr<Entity>> result;

            for (const auto &entity : _entities)
            {
                if (entity->hasComponents<TComponent, TOther...>())
                {
                    result.push_back(entity);
                }
            }

            return result;
        }

        std::vector<std::shared_ptr<Entity>> listEntities()
        {
            return _entities;
        }

    private:
        std::vector<std::shared_ptr<Entity>> _entities{};
    };
}