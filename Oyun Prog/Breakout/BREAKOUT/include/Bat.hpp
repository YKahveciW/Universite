#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Bat
{
public:
	Bat();
	sf::Texture		m_Tex;
	sf::Sprite		m_Sprite;

	int				width;
	int				height;
	std::string		m_Color;

	void Ciz(sf::RenderWindow& window);
};