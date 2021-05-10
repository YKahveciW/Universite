#include "Ball.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ball.hpp"
Ball::Ball()
{
	srand(time(NULL));

	switch (rand() % 6)
	{
	case 0:
		m_Color = "blue";
		break;
	case 1:
		m_Color = "green";
		break;
	case 2:
		m_Color = "orange";
		break;
	case 3:
		m_Color = "red";
		break;
	case 4:
		m_Color = "silver";
		break;
	case 5:
		m_Color = "yellow";
		break;
	}
	sf::Image image;
	if (!image.loadFromFile("../../Dependencies/bin/resimler/Balls/ball_" + m_Color + ".png"))
	{
		std::cout << "Dosya acilamadi." << std::endl;
	}
	else
	{
		auto colorImage=image.getPixel(0, 0);
		image.createMaskFromColor(colorImage);
		m_Tex.loadFromImage(image);
		m_Sprite.setTexture(m_Tex);
		m_Sprite.setTextureRect(sf::IntRect(72, 75, 439, 442));
		float scale = 0.1;
		m_Sprite.setScale(scale, scale);
		height = (439 - 72)*scale;
		width = (442 - 75) * scale;
		m_Sprite.setPosition(sf::Vector2f(300 -width/2, 450));
	}

}

void Ball::TopCarptiX()
{
	m_momentum_X = sf::Vector2f(-m_momentum_X.x, m_momentum_X.y);
}
void Ball::TopCarptiY()
{
	m_momentum_Y = sf::Vector2f(m_momentum_Y.x, -m_momentum_Y.y);
}

void Ball::HareketUygulaX()
{
	sf::Vector2f pos = m_Sprite.getPosition();
	m_Sprite.setPosition(sf::Vector2f(pos.x + m_momentum_X.x, pos.y ));
}

void Ball::HareketUygulaY()
{
	sf::Vector2f pos = m_Sprite.getPosition();
	m_Sprite.setPosition(sf::Vector2f(pos.x , pos.y + m_momentum_Y.y));
}

void Ball::Ciz(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}