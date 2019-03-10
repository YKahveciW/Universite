/**        
* @file  Islemler.cpp  
* @description Islemler 
* @course  Veri Yapilari 2. Ogretim B Grubu  
* @assignment  3. Odev
* @date  19.12.2018
* @author  Yasin Kahveci ykyasinykTR@gmail.com---Neva Emel Isler neva.isler@ogr.sakarya.edu.tr  
 */ 
#include "Islemler.h"
#include "AltAgaclar.h"
#include <iostream>
using namespace std;
void Islemler::AgaciOlustur(AltAgaclar ** AltRoot, int Derinlik)
{
	int derinlik = 0, random;
	while (derinlik != Derinlik + 1)
	{
		random = rand() % 1000;
		AltAgacEkle(AltRoot, random);
		derinlik = DerinlikKontrol(AltRoot);
	}
}

void Islemler::AltAgacEkle(AltAgaclar ** AltRoot, int YeniVeri)
{
	if (*AltRoot == NULL)
		*AltRoot = new AltAgaclar(YeniVeri);
	else if (YeniVeri < (*AltRoot)->VeriGET())
		AltAgacEkle((*AltRoot)->LtreeGet2P(), YeniVeri);
	else if (YeniVeri > (*AltRoot)->VeriGET())
		AltAgacEkle((*AltRoot)->RtreeGet2P(), YeniVeri);
	else return;
}

int Islemler::DerinlikKontrol(AltAgaclar ** temp)
{
	if (*temp == NULL || temp == NULL)
		return 0;
	else
	{
		int lchild = DerinlikKontrol((*temp)->LtreeGet2P());
		int rchild = DerinlikKontrol((*temp)->RtreeGet2P());
		if (lchild <= rchild)
			return rchild + 1;
		else
			return lchild + 1;
	}
}

void Islemler::AgaclardanMinleriSil(AltAgaclar **temp)
{
	int breakmi = 0;
	while ((*temp)->LtreeGet() != NULL)
	{
		if ((*temp)->LtreeGet()->LtreeGet() == NULL)
		{
			if ((*temp)->LtreeGet()->RtreeGet() != NULL)
			{
				AltAgaclar* Yedek = (*temp)->LtreeGet();
				(*temp)->LtreeSet(Yedek->RtreeGet());
				delete Yedek;
				breakmi = 1;
				break;
			}
			delete (*temp)->LtreeGet();
			(*temp)->LtreeSet(NULL);
			breakmi = 1;
			break;
		}
		temp = (*temp)->LtreeGet2P();

	}
	if (!breakmi)
	{
		if ((*temp)->RtreeGet() != NULL)
		{
			AltAgaclar* Yedek = (*temp);
			(*temp) = Yedek->RtreeGet();
			delete Yedek;
		}
		else
		{
			delete (*temp);
			*temp = NULL;
		}
	}
}

void Islemler::AgaclardanMaxlariSil(AltAgaclar **temp)
{
	int breakmi = 0;
	while ((*temp)->RtreeGet() != NULL)
	{
		if ((*temp)->RtreeGet()->RtreeGet() == NULL)
		{
			if ((*temp)->RtreeGet()->LtreeGet() != NULL)
			{
				AltAgaclar* Yedek = (*temp)->RtreeGet();
				(*temp)->RtreeSet(Yedek->LtreeGet());
				delete Yedek;
				breakmi = 1;
				break;
			}
			delete (*temp)->RtreeGet();
			(*temp)->RtreeSet(NULL);
			breakmi = 1;
			break;
		}
		temp = (*temp)->RtreeGet2P();
	}
	if (!breakmi)
	{
		if ((*temp)->LtreeGet() != NULL)
		{
			AltAgaclar* Yedek = (*temp);
			(*temp) = Yedek->LtreeGet();
			delete Yedek;

		}
		else
		{
			delete (*temp);
			*temp = NULL;
		}
	}
}

void Islemler::LevelOrder(AltAgaclar **temp)
{
	int h = DerinlikKontrol(temp);//DerinlikKontrol
	for (int level = 0; level <= h; level++)
		Yazdir((*temp), level);
	cout << endl;
}

void Islemler::Yazdir(AltAgaclar *alt_Dugum, int seviye)
{
	if (alt_Dugum == NULL)
		return;
	if (seviye == 0)
		cout << alt_Dugum->VeriGET() << " ";
	else
	{
		Yazdir(alt_Dugum->LtreeGet(), seviye - 1);
		Yazdir(alt_Dugum->RtreeGet(), seviye - 1);
	}
}