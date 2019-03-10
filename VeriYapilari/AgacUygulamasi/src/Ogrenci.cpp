#include "Ogrenci.h"
#include<string>
#include<iostream>
using namespace std;
Ogrenci::Ogrenci()
{

}
Ogrenci::Ogrenci(char OgrAdi)
{
	OgrenciAdi=OgrAdi;
}
char Ogrenci::OgrAdiGetir()
{
	return OgrenciAdi;
}

