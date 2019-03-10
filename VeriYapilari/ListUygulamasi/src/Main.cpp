/**        
* @file  Main.cpp  
* @description Program calisma duzeninin bulundugu Main CPP  
* @course  Veri Yapilari 2. Ogretim B Grubu  
* @assignment  3. Odev
* @date  19.12.2018
* @author  Yasin Kahveci ykyasinykTR@gmail.com---Neva Emel Isler neva.isler@ogr.sakarya.edu.tr  
 */ 
#include <iostream>
#include <string>
#include "Agac.h"
#include<locale.h>
#include "Islemler.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	string Sayi;
	cout<<"Sayi Giriniz:";
	cin >> Sayi;
	Agac* anaAgac = NULL;
	Agac* Yedek;
	Agac* Yedek2;
	Islemler ISLEM;
	int secim = 0;
	for (int i = 0; i < Sayi.size(); i++)
	{
		if (i == 0)
		{
			anaAgac = new Agac(int(Sayi[i]) - 48);
		}
		else
		{
			Yedek = anaAgac;
			while (Yedek->LtreeGET() != NULL)
			{
				Yedek = Yedek->LtreeGET();
			}
			Yedek->LtreeSET(new Agac(int(Sayi[i]) - 48));
		}
	}
	do
	{
		cout << "1- Aðaçlardan Maksimum Deðeri Çýkar\n";
		cout << "2- Aðaçlardan Minimum Deðeri Çýkar\n";
		cout << "3- Tüm Aðaçlarý Level Order Yazdýr\n";
		cout << "4 - Çýkýþ\nSecim: ";
		cin >> secim;
		if (secim == 1)
		{
			Yedek = anaAgac;
			while (Yedek->LtreeGET() != NULL)
			{
				ISLEM.AgaclardanMaxlariSil(Yedek->altRtreeGET());
				if (Yedek->AltRtreeGET1P() == NULL)
				{
					if (Yedek == anaAgac)
					{
						Yedek = anaAgac->LtreeGET();
						delete anaAgac;
						anaAgac = Yedek;
						continue;
					}
					Yedek2 = anaAgac;
					while (Yedek2->LtreeGET() != Yedek)
					{
						Yedek2 = Yedek2->LtreeGET();
					}
					Yedek2->LtreeSET(Yedek->LtreeGET());
					delete Yedek;
					Yedek = Yedek2->LtreeGET();
					continue;
				}
				Yedek = Yedek->LtreeGET();
			}
			ISLEM.AgaclardanMaxlariSil(Yedek->altRtreeGET());
			if (Yedek->AltRtreeGET1P() == NULL)
			{
				Yedek2 = anaAgac;
				while (Yedek2->LtreeGET() != Yedek)
				{
					Yedek2 = Yedek2->LtreeGET();
				}
				Yedek2->LtreeSET(Yedek->LtreeGET());
				delete Yedek;
			}
		}
		if (secim == 2)
		{
			Yedek = anaAgac;
			while (Yedek->LtreeGET() != NULL)
			{
				ISLEM.AgaclardanMinleriSil(Yedek->altRtreeGET());
				if (Yedek->AltRtreeGET1P() == NULL)
				{
					if (Yedek == anaAgac)
					{
						Yedek = anaAgac->LtreeGET();
						delete anaAgac;
						anaAgac = Yedek;
						continue;
					}
					Yedek2 = anaAgac;
					while (Yedek2->LtreeGET() != Yedek)
					{
						Yedek2 = Yedek2->LtreeGET();
					}
					Yedek2->LtreeSET(Yedek->LtreeGET());
					delete Yedek;
					Yedek = Yedek2->LtreeGET();
					continue;
				}
				Yedek = Yedek->LtreeGET();
			}
			ISLEM.AgaclardanMinleriSil(Yedek->altRtreeGET());
			if (Yedek->AltRtreeGET1P() == NULL)
			{
				Yedek2 = anaAgac;
				while (Yedek2->LtreeGET() != Yedek)
				{
					Yedek2 = Yedek2->LtreeGET();
				}
				Yedek2->LtreeSET(Yedek->LtreeGET());
				delete Yedek;
			}
		}
		if (secim == 3)
		{
			Yedek = anaAgac;
			while (Yedek->LtreeGET() != NULL)
			{
				ISLEM.LevelOrder(Yedek->altRtreeGET());
				Yedek = Yedek->LtreeGET();
			}
			ISLEM.LevelOrder(Yedek->altRtreeGET());
		}
	} while (secim != 4);
	return 0;
}