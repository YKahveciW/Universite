#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include "Wall.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Bat.hpp"
class Sahne
{
public:
	Sahne();
	void Duvarciz(sf::RenderWindow& pencere);
	void Brickciz(sf::RenderWindow& pencere);
	std::vector<Brick>	m_Brick;
	bool				CarptiMi(Ball& ball,Bat& bat);
private:
	std::vector<int>	 m_Duvar;
	
};