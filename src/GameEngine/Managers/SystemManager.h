#pragma once

#include "vector"
#include "memory"

#include "Systems/System.h"

namespace engine
{
    class SystemManager
    {
    public:
        template<class TSystem>
        std::shared_ptr<TSystem> registerSystem(TSystem& system)
        {
            _systems.push_back(std::make_shared<TSystem>(system));

            return std::static_pointer_cast<TSystem>(_systems.back());
        }

        std::vector<std::shared_ptr<System>> listSystem() const
        {
            return _systems;
        }

    private:
        std::vector<std::shared_ptr<System>> _systems{};
    };
}