#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Wall
{
public:
	Wall(sf::Vector2f pos,std::string Color);
	sf::Texture		m_Tex;
	sf::Sprite		m_Sprite;

	sf::Vector2f	m_Position;

	void			Ciz(sf::RenderWindow& window);
};