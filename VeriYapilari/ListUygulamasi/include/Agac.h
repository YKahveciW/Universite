#ifndef Agac_H
#define Agac_H
#include<iostream>
#include "AltAgaclar.h"
class Agac
{
private:
	Agac* Ltree = NULL;
	AltAgaclar* altRtree = NULL;
public:

	Agac(int);
	Agac* LtreeGET();
	void LtreeSET(Agac*);
	AltAgaclar** altRtreeGET();
	AltAgaclar* AltRtreeGET1P();

};
#endif