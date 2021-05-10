#include "Oyun.hpp"
#include "Sahne.hpp"
#include "Ball.hpp"
#include "Bat.hpp"


Sahne sahne;
Bat bat;
Ball ball;

Oyun::Oyun()
{
	m_cerceveSuresi = 1.0f / 60.0f;
}

void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (bat.m_Sprite.getPosition().x + 5 + 116 < 560 && !bat.m_Sprite.getGlobalBounds().intersects(ball.m_Sprite.getGlobalBounds()))
		{
			bat.m_Sprite.setPosition(bat.m_Sprite.getPosition().x + 5, bat.m_Sprite.getPosition().y);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (bat.m_Sprite.getPosition().x - 5 > 40 && !bat.m_Sprite.getGlobalBounds().intersects(ball.m_Sprite.getGlobalBounds()))
		{
			bat.m_Sprite.setPosition(bat.m_Sprite.getPosition().x - 5, bat.m_Sprite.getPosition().y);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!m_basla)
		{
			m_basla = true;
		}
	}
}

void Oyun::sahneGuncelle()
{
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		oyunKurallariUygula();
		girisKontrol();
		sahneCiz();
		m_gecenSure -= sf::seconds(m_cerceveSuresi);
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();

	ball.Ciz(m_pencere.pencereGetir());
	bat.Ciz(m_pencere.pencereGetir());
	sahne.Duvarciz(m_pencere.pencereGetir());
	sahne.Brickciz(m_pencere.pencereGetir());

	m_pencere.cizimiBitir();
}

void Oyun::saatiYenidenBaslat()
{
	m_gecenSure += m_saat.restart();
}

void Oyun::oyunKurallariUygula()
{
	if (m_basla)
	{
		ball.HareketUygulaX();
		if (sahne.CarptiMi(ball,bat))
		{
			ball.TopCarptiX();
			ball.HareketUygulaX();
		}
		ball.HareketUygulaY();
		if (sahne.CarptiMi(ball,bat))
		{
			ball.TopCarptiY();
			ball.HareketUygulaY();
		}
	}
}

bool Oyun::bittimi()
{
	return m_pencere.kapandimi();
}
