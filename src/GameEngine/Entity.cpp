#include "Entity.h"

namespace engine
{
    Entity::Entity() : _id(Helper::generateRandomString()), _components(128) { }
    Entity::Entity(std::string& id) : _id(id), _components(128) { }

    std::string Entity::getId() const
    {
        return _id;
    }

    void Entity::addTag(const std::string &tag)
    {
        _tags.erase(tag);
    }

    bool Entity::hasTag(const std::string &tag) const
    {
        return _tags.contains(tag);
    }
}
