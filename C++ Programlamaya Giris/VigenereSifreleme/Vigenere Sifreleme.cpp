#include <iostream>
using namespace std;
class Sifre
{
public:
	Sifre(char *, char *);
	Sifre();

	char * sifrele(char *);
	char * sifrecoz(char *);
	void sifrekelimesiata();
private:
	char* alfabe;
	char* sifrekelimesi;
	char** vigenereMatrisi;
};
int main()
{
	char ALFABEMETIN[50];
	char SIFREMETIN[20];
	char METIN[100];
	char DESIFRELENECEKMETIN[100];
	cout << "ALFABE: ";
	cin >> ALFABEMETIN;
	cout << "SIFRE: ";
	cin >> SIFREMETIN;
	Sifre Kripto(ALFABEMETIN, SIFREMETIN);
	int secim = 0;
	do
	{
		cout << "1-Sifreleme Islemi\n";
		cout << "2-Desifreleme Islemi\n";
		cout << "3-Sifre degistir Islemi\n";
		cout << "4-Cikis\n";
		cout << "Secim: ";
		cin >> secim;
		if (secim == 1)
		{
			cout << "METIN: ";
			cin >> METIN;
			cout << "SIFRELENMIS METIN: " << Kripto.sifrele(METIN) << endl;
		}
		if (secim == 2)
		{
			cout << "DESIFRELENECEK METIN: ";
			cin >> DESIFRELENECEKMETIN;
			cout << "DESIFRE METIN: " << Kripto.sifrecoz(DESIFRELENECEKMETIN) << endl;
		}
		if (secim==3)
		{
			cout << "YENI SIFRE KELIMESINI GIRINIZ:";
			Kripto.sifrekelimesiata();
		}
	} while (secim!=4);
	system("PAUSE");
	return 0;
}


Sifre::Sifre()
{

}

Sifre::Sifre(char * alfabe, char * sifre)
{
	this->alfabe = alfabe;
	sifrekelimesi = sifre;
	vigenereMatrisi = new char*[strlen(alfabe)];
	for (int i = 0; i < strlen(alfabe); i++)
	{
		vigenereMatrisi[i] = new char[strlen(alfabe)];
	}
	int z = 0;
	for (int i = 0; i < strlen(alfabe); i++)
	{
		for (int j = 0; j < strlen(alfabe) + 1; j++)
		{
			if (z == strlen(alfabe))
				z = 0;
			if (i == 0 && j == 0)
				vigenereMatrisi[i][j] = 0;
			else
			{
				vigenereMatrisi[i][j] = alfabe[z];
				z++;
			}
		}
	}
}



char * Sifre::sifrele(char *Sifrelencek)
{
	char* Ceviri = new char[strlen(Sifrelencek)];
	int x = 0, y = 0;
	for (int i = 0; i < strlen(Sifrelencek); i++)
	{
		for (x = 0; x < strlen(alfabe) + 1; x++)
		{
			if (Sifrelencek[i] == vigenereMatrisi[x][0])
			{
				break;
			}
		}
		for (y = 0; y < strlen(alfabe); y++)
		{
			if (sifrekelimesi[i%strlen(sifrekelimesi)] == vigenereMatrisi[0][y])
			{
				break;
			}
		}
		Ceviri[i] = vigenereMatrisi[x][y];
	}
	Ceviri[strlen(Sifrelencek)] = '\0';
	return Ceviri;
}

char * Sifre::sifrecoz(char *SifresiCozulcek)
{
	char* Ceviri = new char[strlen(SifresiCozulcek)];
	int x, y;
	for (int i = 0; i < strlen(SifresiCozulcek); i++)
	{
		for (y = 0; y < strlen(alfabe); y++)
		{
			if (sifrekelimesi[i%strlen(sifrekelimesi)] == vigenereMatrisi[0][y])
			{
				break;
			}
		}
		for (x = 0; x < strlen(alfabe) + 1; x++)
		{
			if (SifresiCozulcek[i] == vigenereMatrisi[x][y])
			{
				break;
			}
		}

		Ceviri[i] = vigenereMatrisi[x][0];
	}
	Ceviri[strlen(SifresiCozulcek)] = '\0';
	return Ceviri;
}

void Sifre::sifrekelimesiata()
{
	cin >> sifrekelimesi;
}