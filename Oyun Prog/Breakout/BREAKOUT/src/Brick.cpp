#include "Brick.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include <chrono>
#include <random>

Brick::Brick(sf::Vector2f pos)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_int_distribution<int> distributionInteger(0, 4);

	switch (distributionInteger(generator))
	{
		case 0:
			m_Color = "blue";
			break;
		case 1:
			m_Color = "green";
			break;
		case 2:
			m_Color = "pink";
			break;
		case 3:
			m_Color = "violet";
			break;
		case 4:
			m_Color = "yellow";
			break;
	}
	
	sf::Texture* tex = TextureManager::getInstance()->getTexture(m_Color);


	m_Sprite.setTexture(*tex);
	m_Sprite.setTextureRect(sf::IntRect(141, 178, 373, 280));
	float scale = 88.0/(373-141);
	m_Sprite.setScale(scale, scale);
	m_Sprite.setPosition(pos);
}

void Brick::Hit()
{
	m_Color = "c_" + m_Color;
	sf::Texture* tex = TextureManager::getInstance()->getTexture(m_Color);

	m_Sprite.setTexture(*tex);
	m_Sprite.setTextureRect(sf::IntRect(141, 178, 373, 280));
	float scale = 88.0 / (373 - 141);
	m_Sprite.setScale(scale, scale);
}

void Brick::Ciz(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}
