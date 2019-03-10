/**        
* @file  Agac.cpp  
* @description Agac Classinin Kodlarinin bulundugu CPP  
* @course  Veri Yapilari 2. Ogretim B Grubu  
* @assignment  3. Odev
* @date  19.12.2018
* @author  Yasin Kahveci ykyasinykTR@gmail.com---Neva Emel Isler neva.isler@ogr.sakarya.edu.tr  
 */ 
#include "Agac.h"
#include "Islemler.h"

Agac::Agac(int Derinlik)
{
	Islemler islem;
	islem.AgaciOlustur(&altRtree, Derinlik);
}

Agac * Agac::LtreeGET()
{
	return Ltree;
}

void Agac::LtreeSET(Agac* ltree)
{
	this->Ltree = ltree;
}

AltAgaclar ** Agac::altRtreeGET()
{
	return &altRtree;
}

AltAgaclar * Agac::AltRtreeGET1P()
{
	return altRtree;
}
