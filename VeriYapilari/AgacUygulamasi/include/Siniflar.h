#ifndef Siniflar_H
#define Siniflar_H
#include <iostream>
#include <string>
#include "Ogrenci.h"
using namespace std;
class Siniflar
{
private:
	char SinifAdi;
public:
	int atama = 0;
	Siniflar(char);
	Siniflar();
	char SinifAD();
	void SinifOlustur();
	void SinifiListele();
	Ogrenci *ogrencidizisi[8];
};
#endif 