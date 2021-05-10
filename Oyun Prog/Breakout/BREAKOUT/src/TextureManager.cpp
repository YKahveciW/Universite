#include "TextureManager.hpp"
#include <iostream>
TextureManager* TextureManager::m_Instance = 0;
TextureManager* TextureManager::getInstance()
{
	if (m_Instance)
	{
		return m_Instance;
	}

	m_Instance = new TextureManager();

	return m_Instance;
}
sf::Texture* TextureManager::getTexture(std::string color)
{
	return m_TextureMap[color];
}
TextureManager::TextureManager()
{
	for (size_t i = 0; i < 5; i++)
	{
		std::string m_Color;
		switch (i)
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
		sf::Image image;
		if (!image.loadFromFile("../../Dependencies/bin/resimler/Bricks/brick_" + m_Color + "_small.png"))
		{
			std::cout << "Dosya acilamadi." << std::endl;
		}
		auto pxlColor = image.getPixel(0, 0);
		image.createMaskFromColor(pxlColor);
		sf::Texture* tex = new sf::Texture();
		tex->loadFromImage(image);
		m_TextureMap[m_Color] = tex;
	}
	for (size_t i = 0; i < 5; i++)
	{
		std::string m_Color;
		switch (i)
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
		sf::Image image;
		if (!image.loadFromFile("../../Dependencies/bin/resimler/Bricks/brick_" + m_Color + "_small_cracked.png"))
		{
			std::cout << "Dosya acilamadi." << std::endl;
		}
		auto pxlColor = image.getPixel(0, 0);
		image.createMaskFromColor(pxlColor);
		sf::Texture* tex = new sf::Texture();
		tex->loadFromImage(image);
		m_Color = "c_" + m_Color;
		m_TextureMap[m_Color] = tex;
	}
}