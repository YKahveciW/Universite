#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Brick
{
public:
	Brick(sf::Vector2f pos);

	sf::Sprite		m_Sprite;
	std::string		m_Color;

	int width =88;
	int height = 38;

	int Can = 1;

	void			Hit();
	void			Ciz(sf::RenderWindow& window);
};