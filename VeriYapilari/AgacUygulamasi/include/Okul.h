#ifndef Okul_H
#define Okul_H
#include"Siniflar.h"
#include"Ogrenci.h"
class Okul
{
private:
	char sayi=0;
	char okunankelime;
	int maxeleman = 0;
	Siniflar *sinifdizisi[5];
	int sayac = 0;
public:
	Okul();
	void OkuldaSinifOlustur();
	friend ostream& operator<<(ostream& ekran, Siniflar &sinif) {
		ekran << sinif.SinifAD();
		return ekran;
	}
	friend ostream& operator<<(ostream& ekran, Ogrenci &ogr) {
		ekran << ogr.OgrAdiGetir();
		return ekran;
	}
	void SinifDegistir(char, char);
	void OgrDegis(char,char);
	void Yazdir();	
};
#endif