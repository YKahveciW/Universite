#ifndef Islemler_H
#define Islemler_H
#include "AltAgaclar.h"
#include "Agac.h"
class Islemler
{
public:
	void AgaciOlustur(AltAgaclar **, int);
	void AltAgacEkle(AltAgaclar **, int);
	int DerinlikKontrol(AltAgaclar **);
	void AgaclardanMinleriSil(AltAgaclar **);
	void AgaclardanMaxlariSil(AltAgaclar **);
	void LevelOrder(AltAgaclar **);
	void Yazdir(AltAgaclar *, int);
};
#endif
