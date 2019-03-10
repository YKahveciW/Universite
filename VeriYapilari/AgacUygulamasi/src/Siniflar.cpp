#include "Siniflar.h"
#include "Ogrenci.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
Siniflar::Siniflar()
{

}
Siniflar::Siniflar(char Ad)
{
	SinifAdi = Ad;
}
char Siniflar::SinifAD()
{
	return SinifAdi;
}
void Siniflar::SinifOlustur()
{
	ifstream DosyaOku("okul.txt");
	string str;
	char SatirAdi;
	while (getline(DosyaOku,str))
	{
		for (int okuKarakter = 0; okuKarakter < str.size(); okuKarakter++) 
		{
			if (okuKarakter == 0)
			{
				SatirAdi = str[okuKarakter];
			}
			else if (SatirAdi==SinifAdi)
			{
				if (str[okuKarakter] == ' ')
				{
					continue;
				}
				else
				{	
					ogrencidizisi[atama] = new Ogrenci(str[okuKarakter]);
					atama++;
				}
			}
		}	
	}
}
void Siniflar::SinifiListele()
{
	int a = 0;
	while (ogrencidizisi[a]!=NULL)
	{
		if (atama == a)
		{
			break;
		}
		ogrencidizisi[a]->OgrAdiGetir();
		cout<<"   " << ogrencidizisi[a] << endl;
		a++;
	}
}