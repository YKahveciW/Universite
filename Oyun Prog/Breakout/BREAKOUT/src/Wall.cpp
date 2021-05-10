#include "Wall.hpp"
#include <iostream>

Wall::Wall(sf::Vector2f pos,std::string m_Color)
{
	sf::Image image;
	if (!image.loadFromFile("../../Dependencies/bin/resimler/Walls/brick" + m_Color + ".png"))
	{
		std::cout << "Dosya acilamadi." << std::endl;
	}
	else
	{
		auto maskColor = image.getPixel(0, 0);
		image.createMaskFromColor(maskColor);
		m_Tex.loadFromImage(image);
		float x = 217-43;
		float scale = 40/x;
		m_Sprite.setTexture(m_Tex);
		m_Sprite.setTextureRect(sf::IntRect(43, 45, 217, 219));
		m_Sprite.setScale(scale, scale);
		m_Sprite.setPosition(pos);
	}
}

void Wall::Ciz(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}
