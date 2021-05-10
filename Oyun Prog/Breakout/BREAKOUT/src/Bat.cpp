#include "Bat.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Bat::Bat()
{
	srand(time(NULL));

	switch (rand() % 5)
	{
	case 0:
		m_Color = "black";
		break;
	case 1:
		m_Color = "blue";
		break;
	case 2:
		m_Color = "orange";
		break;
	case 3:
		m_Color = "pink";
		break;
	case 4:
		m_Color = "yellow";
		break;
	}
	sf::Image image;
	if (!image.loadFromFile("../../Dependencies/bin/resimler/Bats/bat_" + m_Color + ".png"))
	{
		std::cout << "Dosya acilamadi." << std::endl;
	}
	else
	{
		auto pxlColor = image.getPixel(0, 0);
		image.createMaskFromColor(pxlColor);
		m_Tex.loadFromImage(image);
		m_Sprite.setTexture(m_Tex);
		m_Sprite.setTextureRect(sf::IntRect(25,179,489,280));
		float scale = 0.25;
		width = (489 - 25) * scale;
		height = (280 - 179) * scale;
		m_Sprite.setScale(scale, scale);
		m_Sprite.setPosition(sf::Vector2f(300 - (489-25)*scale/2 , 650));
	}
}

void Bat::Ciz(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}
