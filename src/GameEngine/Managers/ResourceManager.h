#pragma once

#include "memory"
#include "vector"
#include "map"
#include "filesystem"

#include "SFML/Graphics.hpp"

#include "Utils/Helper.h"
#include "ResourceType.h"

namespace engine
{
    class ResourceManager
    {
    public:
        void loadResources(const std::string& path);

        std::shared_ptr<sf::Font> getFont(const std::string& name);

        std::shared_ptr<sf::Texture> getTexture(const std::string& name);
        std::vector<std::shared_ptr<sf::Texture>> listTextures(const std::string& startsWith);

    private:
        std::map<std::string, std::shared_ptr<sf::Font>> _fonts;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;

        void loadFontResource(const std::filesystem::directory_entry& file);
        void loadTextureResource(const std::filesystem::directory_entry& file);

        static ResourceType getResourceType(const std::filesystem::directory_entry& file);
    };
}