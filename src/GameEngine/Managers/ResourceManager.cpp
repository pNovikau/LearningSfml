#include "ResourceManager.h"

namespace engine
{
    void ResourceManager::loadResources(const std::string &path)
    {
        auto iter = std::filesystem::directory_iterator(path);

        if (!iter->exists())
            return;

        for (const auto& file : iter)
        {
            switch (getResourceType(file))
            {
                case ResourceType::Font:
                    loadFontResource(file);
                    break;
                case ResourceType::Texture:
                    loadTextureResource(file);
                    break;
                case ResourceType::None:
                    //TODO: add log
                    break;
            }
        }
    }

    std::shared_ptr<sf::Font> ResourceManager::getFont(const std::string &name)
    {
        auto normalizedName = Helper::toUpperCopy(name);

        return _fonts[normalizedName];
    };

    std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string &name)
    {
        auto normalizedName = Helper::toUpperCopy(name);

        return _textures[normalizedName];
    }

    std::vector<std::shared_ptr<sf::Texture>> ResourceManager::listTextures(const std::string &startsWith)
    {
        std::vector<std::shared_ptr<sf::Texture>> result;
        auto normalizedStartWith = Helper::toUpperCopy(startsWith);

        for (auto& pair : _textures)
        {
            if (pair.first.starts_with(normalizedStartWith))
                result.push_back(pair.second);
        }

        return result;
    }

    void ResourceManager::loadFontResource(const std::filesystem::directory_entry &file)
    {
        sf::Font font;

        if (!font.loadFromFile(file.path().string()))
        {} //TODO: handle error

        auto fullName = file.path().filename().string();
        auto lastIndex = fullName.find_last_of('.');
        auto normalizedKey = Helper::toUpperCopy(fullName.substr(0, lastIndex));
        _fonts.emplace(normalizedKey, std::make_shared<sf::Font>(font));
    }

    void ResourceManager::loadTextureResource(const std::filesystem::directory_entry &file)
    {
        sf::Texture texture;

        if (!texture.loadFromFile(file.path().string()))
        {} //TODO: handle error

        auto fullName = file.path().filename().string();
        auto lastIndex = fullName.find_last_of('.');
        auto normalizedKey = Helper::toUpperCopy(fullName.substr(0, lastIndex));
        _textures.emplace(normalizedKey, std::make_shared<sf::Texture>(texture));
    }

    ResourceType ResourceManager::getResourceType(const std::filesystem::directory_entry &file)
    {
        auto fileExtension = file.path().extension();

        if (fileExtension == ".png")
            return ResourceType::Texture;

        if (fileExtension == ".ttf")
            return ResourceType::Font;

        return ResourceType::None;
    }
}