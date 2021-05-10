#pragma once
#include "Pencere.hpp"
#include "Brick.hpp"
#include <vector>
#include <string>
class Oyun
{
public:
	Oyun();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();
	void saatiYenidenBaslat();
	void oyunKurallariUygula();
	bool bittimi();
private:
	bool m_basla=false;
	Pencere m_pencere;
	sf::Clock m_saat;
	sf::Time m_gecenSure;
	float m_cerceveSuresi;
};