#include "Ogrenci.h"
#include "Siniflar.h"
#include "Okul.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int Secim = 0;
	Okul *OkulNesnesi = new Okul();
	OkulNesnesi->OkuldaSinifOlustur();
	char Degistir1, Degistir2;
	do
	{
		system("cls");
		OkulNesnesi->Yazdir();
		cout << "1-Sinif Degistir \n";
		cout << "2-Ogrenci Degistir \n";
		cout << "3-Cikis\n";
		cin >> Secim;
		switch (Secim)
		{
		case 1:

			cout << "Degistirilcek ilk sinifi Giriniz : ";
			cin >> Degistir1;
			cout << "Degistirilcek ikinci sinifi Giriniz : ";
			cin >> Degistir2;
			OkulNesnesi->SinifDegistir(Degistir1, Degistir2);
			break;
		case 2:
			cout << "Degistirilcek ilk ogrenciyi Giriniz : ";
			cin >> Degistir1;
			cout << "Degistirilcek ikinci ogrenciyi giriniz: ";
			cin >> Degistir2;
			OkulNesnesi->OgrDegis(Degistir1, Degistir2);
		}
		if (Secim!=3)
		{
		OkulNesnesi->Yazdir();
		system("Pause");
		}
	}while (Secim!=3);

	delete OkulNesnesi;
	system("PAUSE");
	return 0;
}