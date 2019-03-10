#include <iostream>
using namespace std;
struct MATRIS
{
	int Dizi[4][4] = { 25,25,25,25,
		25,25,25,25,
		25,25,25,25,
		25,25,25,25 };
	int AnaMatrisBoyut = sizeof(Dizi) / sizeof(Dizi[0]);
	int CerceveKaymaMiktari;
	int CekirdekBoyut;
	int SonucMatrisBoyut;

}Matris;
void Atama(int **Olustur, int Boyut);//Cekirdek Matrisin degerlerini atamak icin
void Carpma(int **cekirdek, int **sonuc);//Ana Matris ile Cekirdek Matrisi carpip sonuc matrisine esitlemek icin
void Yazdir(int **Yaz_Matris, int Boyut);//Sonuc Matrisi ekrana yazdirmak icin
int main()
{
	int **cekirdek;
	cout << "Cekirdek boyutunu giriniz: ";
	cin >> Matris.CekirdekBoyut;
	cout << "Kayma miktarini giriniz: ";
	cin >> Matris.CerceveKaymaMiktari;
	Matris.SonucMatrisBoyut = ((Matris.AnaMatrisBoyut - Matris.CekirdekBoyut) / Matris.CerceveKaymaMiktari) + 1;
	if (((Matris.AnaMatrisBoyut - Matris.CekirdekBoyut) % Matris.CerceveKaymaMiktari) != 0)
	{
		cout << "Carpmaya Uygun Degil .\n";
		system("PAUSE");
		return 0;
	}
	cekirdek = new int *[Matris.CekirdekBoyut];
	for (int i = 0; i < Matris.CekirdekBoyut; i++)
	{
		cekirdek[i] = new int[Matris.CekirdekBoyut];//Dinamik iki boyutlu dizi
	}
	Atama(cekirdek, Matris.CekirdekBoyut);
	int **sonuc;
	sonuc = new int *[Matris.SonucMatrisBoyut];
	for (int i = 0; i < Matris.SonucMatrisBoyut; i++)
	{
		sonuc[i] = new int[Matris.SonucMatrisBoyut];
	}
	for (int i = 0; i < Matris.SonucMatrisBoyut; i++)
	{
		for (int j = 0; j < Matris.SonucMatrisBoyut; j++)
		{
			sonuc[i][j] = 0;
		}
	}
	Carpma(cekirdek, sonuc);
	Yazdir(sonuc, Matris.SonucMatrisBoyut);
	system("PAUSE");
	return 0;
}
void Atama(int **Olustur, int Boyut)
{
	for (int i = 0; i < Boyut; i++)
	{
		for (int j = 0; j < Boyut; j++)
		{
			cout << "Cekirdek[" << i + 1 << "][" << j + 1 << "]:";
			cin >> Olustur[i][j];
		}
	}
}
void Carpma(int **cekirdek, int **sonuc)
{
	int AnaMatrisX = 0, AnaMatrisY = 0, CekirdekX = 0, CekirdekY = 0;
	for (int i = 0; i < Matris.SonucMatrisBoyut; i++)
	{

		for (int j = 0; j < Matris.SonucMatrisBoyut; j++)
		{

			for (int t = 0; t < Matris.CekirdekBoyut*Matris.CekirdekBoyut; t++)
			{
				sonuc[i][j] += Matris.Dizi[AnaMatrisX][AnaMatrisY] * cekirdek[CekirdekX][CekirdekY];
				if (CekirdekY < Matris.CekirdekBoyut - 1)
				{
					CekirdekY++;
					AnaMatrisY++;
				}
				else if (CekirdekY == Matris.CekirdekBoyut - 1)
				{
					CekirdekY = 0;
					CekirdekX++;
					AnaMatrisY = AnaMatrisY - (Matris.CekirdekBoyut - 1);
					AnaMatrisX++;
				}
			}
			CekirdekX = 0;
			CekirdekY = 0;
			AnaMatrisY += Matris.CerceveKaymaMiktari;
			AnaMatrisX -= Matris.CekirdekBoyut;
		}

		AnaMatrisX += Matris.CerceveKaymaMiktari;
		AnaMatrisY = 0;
	}
}
void Yazdir(int **Yaz_Matris, int Boyut)
{
	for (int i = 0; i < Boyut; i++)
	{
		for (int j = 0; j < Boyut; j++)
		{
			cout << Yaz_Matris[i][j] << " ";
		}
		cout << endl;
	}
}