#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
class TextureManager
{
public:
    static TextureManager* getInstance();
    sf::Texture* getTexture(std::string);
private:
    TextureManager();
    static TextureManager* m_Instance;
    std::map <std::string, sf::Texture*>  m_TextureMap;
};
