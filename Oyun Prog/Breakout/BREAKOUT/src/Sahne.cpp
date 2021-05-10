#include "Sahne.hpp"
#include "Wall.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Wall Green({ 0.0,0.0 }, "");
Wall Blue({ 0.0,0.0 },"_blue");
Wall Pink({ 0.0,0.0 },"_pink_side");
Wall Red({ 0.0,0.0 },"_red");

Sahne::Sahne()
{
	srand(time(NULL));
	for (int i = 0; i < 70; i++)
	{
		m_Duvar.push_back(rand() % 4);
	}

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			Brick brk(sf::Vector2f(80 + j * 88,80 + i * 38 ));
			m_Brick.push_back(brk);
		}
	}
}


void Sahne::Duvarciz(sf::RenderWindow& pencere)
{
	for (int i = 0; i < 15; i++)
	{
		switch (m_Duvar.at(i))
		{
		case 0:
			Green.m_Sprite.setPosition(i * 40.0f, 0.0f);
			Green.Ciz(pencere);
			break;
		case 1:
			Blue.m_Sprite.setPosition(i * 40.0f, 0.0f);
			Blue.Ciz(pencere);
			break;
		case 2:
			Pink.m_Sprite.setPosition(i * 40.0f, 0.0f);
			Pink.Ciz(pencere);
			break;
		case 3:
			Red.m_Sprite.setPosition(i * 40.0f, 0.0f);
			Red.Ciz(pencere);
			break;
		}
	}
	for (int i = 15; i < 30; i++)
	{
		int y = i - 15;
		switch (m_Duvar.at(i))
		{
		case 0:
			Green.m_Sprite.setPosition(y * 40.0f, 760.0f);
			Green.Ciz(pencere);
			break;
		case 1:
			Blue.m_Sprite.setPosition(y * 40.0f, 760.0f);
			Blue.Ciz(pencere);
			break;
		case 2:
			Pink.m_Sprite.setPosition(y * 40.0f, 760.0f);
			Pink.Ciz(pencere);
			break;
		case 3:
			Red.m_Sprite.setPosition(y * 40.0f, 760.0f);
			Red.Ciz(pencere);
			break;
		}
	}
	for (int i = 30; i < 50; i++)
	{
		int y = i - 30;
		switch (m_Duvar.at(i))
		{
		case 0:
			Green.m_Sprite.setPosition(0.0f, y * 40.0f);
			Green.Ciz(pencere);
			break;
		case 1:
			Blue.m_Sprite.setPosition(0.0f, y * 40.0f);
			Blue.Ciz(pencere);
			break;
		case 2:
			Pink.m_Sprite.setPosition( 0.0f,y * 40.0f);
			Pink.Ciz(pencere);
			break;
		case 3:
			Red.m_Sprite.setPosition(0.0f,y * 40.0f);
			Red.Ciz(pencere);
			break;
		}
	}
	for (int i = 50; i < 70; i++)
	{
		int y = i - 50;
		switch (m_Duvar.at(i))
		{
		case 0:
			Green.m_Sprite.setPosition(560.0f, y * 40.0f);
			Green.Ciz(pencere);
			break;
		case 1:
			Blue.m_Sprite.setPosition(560.0f, y * 40.0f);
			Blue.Ciz(pencere);
			break;
		case 2:
			Pink.m_Sprite.setPosition(560.0f, y * 40.0f);
			Pink.Ciz(pencere);
			break;
		case 3:
			Red.m_Sprite.setPosition(560.0f, y * 40.0f);
			Red.Ciz(pencere);
			break;
		}
	}
}

void Sahne::Brickciz(sf::RenderWindow& pencere)
{
	if (m_Brick.size()==0)
	{
		pencere.display();
		system("PAUSE");
		exit(0);
	}
	for (size_t i = 0; i < m_Brick.size(); i++)
	{
		m_Brick.at(i).Ciz(pencere);
	}
}

bool Sahne::CarptiMi(Ball& ball,Bat& bat)
{
	
	for (size_t i = 0; i < m_Brick.size(); i++)
	{
		if (m_Brick.at(i).m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x
			&& m_Brick.at(i).m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y
			&& m_Brick.at(i).m_Sprite.getPosition().x + m_Brick.at(i).width > ball.m_Sprite.getPosition().x
			&& m_Brick.at(i).m_Sprite.getPosition().y + m_Brick.at(i).height > ball.m_Sprite.getPosition().y)
		{
			if (m_Brick.at(i).Can)
			{
				m_Brick.at(i).Hit();
				m_Brick.at(i).Can = 0;
			}
			else
			{
				m_Brick.erase(m_Brick.begin() + i);
			}
			return true;
		}
		if (m_Brick.at(i).m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x + ball.width
			&& m_Brick.at(i).m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y + ball.height
			&& m_Brick.at(i).m_Sprite.getPosition().x + m_Brick.at(i).width > ball.m_Sprite.getPosition().x + ball.width
			&& m_Brick.at(i).m_Sprite.getPosition().y + m_Brick.at(i).height > ball.m_Sprite.getPosition().y + ball.height)
		{
			if (m_Brick.at(i).Can)
			{
				m_Brick.at(i).Hit();
				m_Brick.at(i).Can = 0;
			}
			else
			{
				m_Brick.erase(m_Brick.begin() + i);
			}
			return true;
		}
		if (m_Brick.at(i).m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x + ball.width
			&& m_Brick.at(i).m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y 
			&& m_Brick.at(i).m_Sprite.getPosition().x + m_Brick.at(i).width > ball.m_Sprite.getPosition().x + ball.width
			&& m_Brick.at(i).m_Sprite.getPosition().y + m_Brick.at(i).height > ball.m_Sprite.getPosition().y)
		{
			if (m_Brick.at(i).Can)
			{
				m_Brick.at(i).Hit();
				m_Brick.at(i).Can = 0;
			}
			else
			{
				m_Brick.erase(m_Brick.begin() + i);
			}
			return true;
		}
		if (m_Brick.at(i).m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x
			&& m_Brick.at(i).m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y + ball.height
			&& m_Brick.at(i).m_Sprite.getPosition().x + m_Brick.at(i).width > ball.m_Sprite.getPosition().x
			&& m_Brick.at(i).m_Sprite.getPosition().y + m_Brick.at(i).height > ball.m_Sprite.getPosition().y + ball.height)
		{
			if (m_Brick.at(i).Can)
			{
				m_Brick.at(i).Hit();
				m_Brick.at(i).Can = 0;
			}
			else
			{
				m_Brick.erase(m_Brick.begin() + i);
			}
			return true;
		}
	}
	
	if (ball.m_Sprite.getPosition().x <40 ||
		ball.m_Sprite.getPosition().x > 560 ||
		ball.m_Sprite.getPosition().y < 40 ||
		ball.m_Sprite.getPosition().y > 760)
	{
		return true;
	}
	if (ball.m_Sprite.getPosition().x +ball.width < 40 ||
		ball.m_Sprite.getPosition().x + ball.width> 560 ||
		ball.m_Sprite.getPosition().y + ball.height < 40 ||
		ball.m_Sprite.getPosition().y + ball.height> 760)
	{
		
		return true;
	}
	if (ball.m_Sprite.getPosition().x + ball.width < 40 ||
		ball.m_Sprite.getPosition().x + ball.width> 560 ||
		ball.m_Sprite.getPosition().y < 40 ||
		ball.m_Sprite.getPosition().y > 760)
	{
		
		return true;
	}
	if (ball.m_Sprite.getPosition().x < 40 ||
		ball.m_Sprite.getPosition().x > 560 ||
		ball.m_Sprite.getPosition().y + ball.height < 40 ||
		ball.m_Sprite.getPosition().y + ball.height> 760)
	{

		return true;
	}

	
	if (bat.m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x
		&& bat.m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y
		&& bat.m_Sprite.getPosition().x + bat.width > ball.m_Sprite.getPosition().x
		&& bat.m_Sprite.getPosition().y + bat.height > ball.m_Sprite.getPosition().y)
	{
		return true;
	}
	if (bat.m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x + ball.width
		&& bat.m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y + ball.height
		&& bat.m_Sprite.getPosition().x + bat.width > ball.m_Sprite.getPosition().x + ball.width
		&& bat.m_Sprite.getPosition().y + bat.height > ball.m_Sprite.getPosition().y + ball.height)
	{
		return true;
	}
	if (bat.m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x + ball.width
		&& bat.m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y
		&& bat.m_Sprite.getPosition().x + bat.width > ball.m_Sprite.getPosition().x + ball.width
		&& bat.m_Sprite.getPosition().y + bat.height > ball.m_Sprite.getPosition().y)
	{
		return true;
	}
	if (bat.m_Sprite.getPosition().x < ball.m_Sprite.getPosition().x
		&& bat.m_Sprite.getPosition().y < ball.m_Sprite.getPosition().y + ball.height
		&& bat.m_Sprite.getPosition().x + bat.width > ball.m_Sprite.getPosition().x
		&& bat.m_Sprite.getPosition().y + bat.height > ball.m_Sprite.getPosition().y + ball.height)
	{
		return true;
	}
	

	return false;
}