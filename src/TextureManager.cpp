#include "TextureManager.hpp"
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

TextureManager::~TextureManager()
{
    for(std::map<std::string, sf::Texture*>::iterator it(m_textureList.begin()); it!=m_textureList.end(); it++)
    {
        delete it->second;
    }
    m_textureList.clear();
}

inline bool TextureManager::SearchTexture(const std::string& link)
{
    std::map<std::string, sf::Texture*>::iterator it;
    it=m_textureList.find(link);
    if(it==m_textureList.end())
        return false;
    else
        return true;
}

sf::Texture& TextureManager::GetTexture(const std::string& link)
{
    if(!SearchTexture(link))
    {
        std::cout<<"load image"<<std::endl;
        m_textureList.insert(std::make_pair(link, new sf::Texture));
        std::map<std::string, sf::Texture*>::iterator it(m_textureList.find(link));
        if(!it->second->loadFromFile(link))
        {
            std::cerr<<"Failed to load : "<<link<<std::endl;
        }
    }
    return *m_textureList.find(link)->second;
}

bool TextureManager::DeleteTexture(const std::string& link)
{
    if(SearchTexture(link))
    {
        std::map<std::string, sf::Texture*>::iterator it(m_textureList.find(link));
        delete it->second;
        m_textureList.erase(it);
        return true;
    }
    return false;
}

void TextureManager::DeleteAll()
{
    for(std::map<std::string, sf::Texture*>::iterator it(m_textureList.begin()); it!=m_textureList.end(); it++)
    {
        delete it->second;
    }
    m_textureList.clear();
}

TextureManager& TextureManager::GetInstance()
{
    static TextureManager instance;
    return instance;
}
