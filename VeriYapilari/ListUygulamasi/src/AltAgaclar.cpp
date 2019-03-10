/**        
* @file  AltAgaclar.cpp  
* @description AltAgaclar Classinin Kodlarinin bulundugu CPP  
* @course  Veri Yapilari 2. Ogretim B Grubu  
* @assignment  3. Odev
* @date  19.12.2018
* @author  Yasin Kahveci ykyasinykTR@gmail.com---Neva Emel Isler neva.isler@ogr.sakarya.edu.tr  
 */
#include "AltAgaclar.h"

AltAgaclar::AltAgaclar(int veri)
{
	this->veri = veri;
}

int AltAgaclar::VeriGET()
{
	if (veri == -1)
	{
		return -1;
	}
	return veri;
}

AltAgaclar * AltAgaclar::RtreeGet()
{
	return Rtree;
}

AltAgaclar * AltAgaclar::LtreeGet()
{
	return Ltree;
}

AltAgaclar ** AltAgaclar::RtreeGet2P()
{
	return &Rtree;
}

AltAgaclar ** AltAgaclar::LtreeGet2P()
{
	return &Ltree;
}

void AltAgaclar::RtreeSet(AltAgaclar* Yeni)
{
	Rtree = Yeni;
}

void AltAgaclar::LtreeSet(AltAgaclar* Yeni)
{
	Ltree = Yeni;
}
