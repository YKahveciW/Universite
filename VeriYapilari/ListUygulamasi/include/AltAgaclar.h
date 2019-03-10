#ifndef AltAgaclar_H
#define AltAgaclar_H
#include<iostream>
class AltAgaclar
{
private:
	int veri = -1;
	AltAgaclar* Ltree = NULL;
	AltAgaclar* Rtree = NULL;
public:
	AltAgaclar(int);
	int VeriGET();
	AltAgaclar* RtreeGet();
	AltAgaclar* LtreeGet();
	AltAgaclar** RtreeGet2P();
	AltAgaclar** LtreeGet2P();
	void RtreeSet(AltAgaclar*);
	void LtreeSet(AltAgaclar*);
};
#endif