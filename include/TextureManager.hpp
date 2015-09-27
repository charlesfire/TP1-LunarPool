#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <string>

namespace sf
{
    class Texture;
}

class TextureManager
{
    public:
        sf::Texture& GetTexture(const std::string& link);
        bool DeleteTexture(const std::string& link);
        void DeleteAll();
        static TextureManager& GetInstance();
    private:
        TextureManager() = default;
        virtual ~TextureManager();
        std::map<std::string, sf::Texture*> m_textureList;
        inline bool SearchTexture(const std::string& link);
};

#endif // TEXTUREMANAGER_HPP
