#include <SFML/Graphics.hpp>
#include "Oyun.hpp"
int main()
{
	Oyun oyun;
	while (!oyun.bittimi())
	{
		oyun.sahneGuncelle();
		oyun.saatiYenidenBaslat();
	}
	return 0;
}