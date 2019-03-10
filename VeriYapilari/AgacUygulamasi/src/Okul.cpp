#include "Okul.h"
#include"Siniflar.h"
#include<iostream>
#include<fstream>
using namespace std;
Okul::Okul()
{
}
void Okul::OkuldaSinifOlustur()
{
	ifstream DosyaOku("okul.txt");
	string str;
	while (getline(DosyaOku, str))
	{
		for (int okunankarakter = 0; okunankarakter < str.size(); okunankarakter++)
		{
			if (okunankarakter == 0)
			{
				sinifdizisi[sayac] = new Siniflar(str[okunankarakter]);
				sinifdizisi[sayac]->SinifOlustur();
				sayac++;
			}
		}
	}
}
void Okul::Yazdir()
{

	for (int i = 0; i <= sayac-1; i++)
	{
		cout << "Sinif Adi : " << sinifdizisi[i]->SinifAD() << "    ";
	}
	cout << endl;
	for (int i = 0; i <= sayac - 1; i++)
	{
		if (i==0)
		{
			maxeleman = sinifdizisi[i]->atama;
		}
		else if (sinifdizisi[i]->atama>maxeleman)
		{
			maxeleman = sinifdizisi[i]->atama;
		}
	}
	for (int DizidenOkunanOgr = 0; DizidenOkunanOgr <maxeleman ; DizidenOkunanOgr++)
	{
		for (int DizidenOkunanSinif = 0; DizidenOkunanSinif <= sayac - 1; DizidenOkunanSinif++)
		{
			if (sinifdizisi[DizidenOkunanSinif]->atama<=DizidenOkunanOgr)
			{
				cout << "                  ";
				continue;
			}
			cout << sinifdizisi[DizidenOkunanSinif]->ogrencidizisi[DizidenOkunanOgr]->OgrAdiGetir()<< "    " << sinifdizisi[DizidenOkunanSinif]->ogrencidizisi[DizidenOkunanOgr] << "    "  ;
		}
		cout<<endl;
	}
}
void Okul::SinifDegistir(char sayi1, char sayi2)
{
	for (int OkunanSinif1 = 0; OkunanSinif1 <= sayac; OkunanSinif1++)
	{
		if (sinifdizisi[OkunanSinif1]->SinifAD() == sayi1)
		{
			for (int OkunanSinif2 = 0; OkunanSinif2 <= sayac; OkunanSinif2++)
			{
				if (sinifdizisi[OkunanSinif2]->SinifAD() == sayi2)
				{
					Siniflar* temp = sinifdizisi[OkunanSinif1];
					sinifdizisi[OkunanSinif1] = sinifdizisi[OkunanSinif2];
					sinifdizisi[OkunanSinif2] = temp;
					OkunanSinif1 = sayac;
					break;
				}
			}
		}
	}
}
void Okul::OgrDegis(char sayi1,char sayi2)
{
	int sayi1x, sayi1y, sayi2x, sayi2y;
	for (int OkunanSinif = 0; OkunanSinif < sayac; OkunanSinif++)
	{
		for (int OkunanOgr = 0; OkunanOgr <= maxeleman; OkunanOgr++)
		{
			if (sinifdizisi[OkunanSinif]->atama <= OkunanOgr)
			{
				break;
			}
			if (sinifdizisi[OkunanSinif]->ogrencidizisi[OkunanOgr]->OgrAdiGetir() == sayi1)
			{
				sayi1x = OkunanSinif;
				sayi1y = OkunanOgr;
			}
			if (sinifdizisi[OkunanSinif]->ogrencidizisi[OkunanOgr]->OgrAdiGetir() == sayi2)
			{
				sayi2x = OkunanSinif;
				sayi2y = OkunanOgr;
			}
		}
	}
	Ogrenci* ogr = sinifdizisi[sayi1x]->ogrencidizisi[sayi1y];
	sinifdizisi[sayi1x]->ogrencidizisi[sayi1y] = sinifdizisi[sayi2x]->ogrencidizisi[sayi2y];
	sinifdizisi[sayi2x]->ogrencidizisi[sayi2y] = ogr;
}