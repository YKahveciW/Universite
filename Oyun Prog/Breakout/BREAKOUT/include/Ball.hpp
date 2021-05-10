#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Ball
{
public:
	Ball();
	sf::Texture		m_Tex;
	sf::Sprite		m_Sprite;

	int				height;
	int				width;

	sf::Vector2f	m_momentum_X = { 3.0,0.0};
	sf::Vector2f	m_momentum_Y = { 0.0,3.0 };

	void			TopCarptiX();
	void			TopCarptiY();
	void			HareketUygulaX();
	void			HareketUygulaY();
	void			Ciz(sf::RenderWindow& window);
private:
	std::string		m_Color;
};