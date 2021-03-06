#include "pch.h"
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
const int DiziX = 20;
const int DiziY = 80;
char Sahne[DiziX][DiziY] = { ' ' };
char tuslar[256];
void MapUcakSil();
void UcakOlustur();
void CerceveOlustur();
void EkranaCiz();
void klavyeOku();
void Mermiilerlet();
void Dusmanilerlet();
void DusmanOlustur();
void MermiOlustur();
void MapSil();
bool UcakZararGorduMu();
void UcakilkKonumYap();
void GAMEOVER();
void UcakYukari();
void UcakAsagi();
void gotoxy(int, int);
void ShowConsoleCursor(bool showFlag);
struct Ucak {
	int Baslangic[5][2] = { {8,1},{9,2},{10,3},{11,2},{12,1} };
	int UcakKonum[5][2] = { {8,1},{9,2},{10,3},{11,2},{12,1} };
}ucak;
int main()
{
	double zamanfarki = 0;
	clock_t anlikzaman = clock();
	clock_t oncekizaman = anlikzaman;
	const double NUM_SECONDS = 1;
	ShowConsoleCursor(false);
	while (true)
	{
		anlikzaman = clock();
		zamanfarki += (double)(anlikzaman - oncekizaman);
		oncekizaman = anlikzaman;
		UcakOlustur();
		gotoxy(0, 0);
		CerceveOlustur();
		EkranaCiz();
		Mermiilerlet();
		Dusmanilerlet();
		if (UcakZararGorduMu())
		{
			gotoxy(0, 0);
			GAMEOVER();
			CerceveOlustur();
			EkranaCiz();
			system("PAUSE");
			system("CLS");
			Sleep(100);
			MapSil();
			UcakilkKonumYap();
			return main();
		}
		MapUcakSil();
		klavyeOku();
		if (tuslar['W']!=0)
		{
			UcakYukari();
		}
		if (tuslar['S'] != 0)
		{
			UcakAsagi();
		}
		if (tuslar['F'] != 0)
		{
			MermiOlustur();
		}
		if (zamanfarki > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
		{
			zamanfarki =0;
			DusmanOlustur();
		}
	}
}

void UcakOlustur()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			Sahne[ucak.UcakKonum[i][j]][ucak.UcakKonum[i][j+1]] = 219;
		}
	}
}
void CerceveOlustur()
{
	for (int i = 0; i < DiziY; i++)
	{
		Sahne[0][i] = 177;
		Sahne[DiziX - 1][i] = 177;
	}
	for (int i = 0; i < DiziX; i++)
	{
		Sahne[i][0] = 177;
		Sahne[i][DiziY - 1] = 177;
	}
}
void EkranaCiz()
{
	for (int i = 0; i < DiziX; i++)
	{
		for (int y = 0; y < DiziY; y++)
		{
			cout << Sahne[i][y];
		}
		cout << endl;
	}
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void klavyeOku()
{
	for (int x = 0; x < 256; x++)
	{
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}
void MapUcakSil()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			Sahne[ucak.UcakKonum[i][j]][ucak.UcakKonum[i][j + 1]] = ' ';
		}
	}
}
void Mermiilerlet()
{
	for (int i = 0; i < DiziX; i++)
	{
		for (int y = 0; y < DiziY; y++)
		{
			if (Sahne[i][y] == char(178))
			{
				if (Sahne[i][y + 1] == char(176)|| Sahne[i][y + 2] == char(176))
				{
					for (int z = -2; z < 3; z++)
					{
						for (int t = 1; t < 4; t++)
						{
							Sahne[i +z][y + t] = ' ';
						}
					}
				}
				Sahne[i][y] = ' ';
				Sahne[i][y + 1] = 178;
				y++;
				}
			if (y == DiziY - 1)
			{
				Sahne[i][y] = ' ';
			}
		}
	}
}
void Dusmanilerlet()
{
	for (int i = 0; i < DiziX; i++)
	{
		for (int y = 0; y < DiziY; y++)
		{
			if (Sahne[i][y] == char(176))
			{
				Sahne[i][y] = ' ';
				Sahne[i][y - 1] = 176;
			}
		}
	}
}
void DusmanOlustur()
{
	int rastgele;
	rastgele = 2 + rand() % 16;
	for (int i = -1; i < 2; i++)
	{
		for (int y = -4; y < -1; y++)
		{
			if (i == 0 && y == -3)
			{
				continue;
			}
			Sahne[rastgele + i][DiziY + y] = 176;
		}
	}
}
void MermiOlustur()
{
	Sahne[ucak.UcakKonum[2][0]][(ucak.UcakKonum[2][1]) + 1] = 178;
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
bool UcakZararGorduMu()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (Sahne[ucak.UcakKonum[i][j]][ucak.UcakKonum[i][j + 1]] ==char(176))
			{
				return true;
			}
		}
	}
	return false;
}

void MapSil()
{
	for (int i = 0; i < DiziX; i++)
	{
		for (int y = 0; y < DiziY; y++)
		{
			Sahne[i][y] = ' ';
		}
	}
}

void UcakilkKonumYap()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ucak.UcakKonum[i][j] = ucak.Baslangic[i][j];
		}
	}
}

void UcakYukari()
{
	for (int i = 0; i < 5; i++)
	{
		if (ucak.UcakKonum[0][0] == 1)
		{
			for (int i = 0; i < 5; i++)
			{
				ucak.UcakKonum[i][0] = i + 1;
			}
		}
		else
		{
			ucak.UcakKonum[i][0]--;
		}
	}
}

void UcakAsagi()
{
	for (int i = 0; i < 5; i++)
	{
		if (ucak.UcakKonum[4][0] != 18)
		{
			ucak.UcakKonum[i][0]++;
		}
	}
}

void GAMEOVER()
{
	//G//
	Sahne[7][20] = 219;
	Sahne[7][21] = 219;
	Sahne[7][22] = 219;
	Sahne[7][23] = 219;
	Sahne[8][20] = 219;
	Sahne[9][20] = 219;
	Sahne[9][22] = 219;
	Sahne[9][23] = 219;
	Sahne[10][20] = 219;
	Sahne[10][23] = 219;
	Sahne[11][20] = 219;
	Sahne[11][21] = 219;
	Sahne[11][22] = 219;
	Sahne[11][23] = 219;
	//A//
	Sahne[7][25] = 219;
	Sahne[7][26] = 219;
	Sahne[7][27] = 219;
	Sahne[8][25] = 219;
	Sahne[8][27] = 219;
	Sahne[9][25] = 219;
	Sahne[9][26] = 219;
	Sahne[9][27] = 219;
	Sahne[10][25] = 219;
	Sahne[10][27] = 219;
	Sahne[11][25] = 219;
	Sahne[11][27] = 219;
	//M//
	Sahne[11][29] = 219;
	Sahne[11][33] = 219;
	Sahne[10][29] = 219;
	Sahne[10][33] = 219;
	Sahne[9][29] = 219;
	Sahne[9][33] = 219;
	Sahne[8][29] = 219;
	Sahne[8][31] = 219;
	Sahne[8][33] = 219;
	Sahne[7][29] = 219;
	Sahne[7][30] = 219;
	Sahne[7][32] = 219;
	Sahne[7][33] = 219;
	//E//
	Sahne[7][35] = 219;
	Sahne[7][36] = 219;
	Sahne[7][37] = 219;
	Sahne[8][35] = 219;
	Sahne[9][35] = 219;
	Sahne[9][36] = 219;
	Sahne[9][37] = 219;
	Sahne[10][35] = 219;
	Sahne[11][35] = 219;
	Sahne[11][36] = 219;
	Sahne[11][37] = 219;
	//O//
	Sahne[7][41] = 219;
	Sahne[7][42] = 219;
	Sahne[7][43] = 219;
	Sahne[8][41] = 219;
	Sahne[8][43] = 219;
	Sahne[9][41] = 219;
	Sahne[9][43] = 219;
	Sahne[10][41] = 219;
	Sahne[10][43] = 219;
	Sahne[11][41] = 219;
	Sahne[11][42] = 219;
	Sahne[11][43] = 219;
	//V//
	Sahne[7][45] = 219;
	Sahne[7][49] = 219;
	Sahne[8][45] = 219;
	Sahne[8][49] = 219;
	Sahne[9][46] = 219;
	Sahne[9][48] = 219;
	Sahne[10][46] = 219;
	Sahne[10][48] = 219;
	Sahne[11][47] = 219;
	//E//
	Sahne[7][51] = 219;
	Sahne[7][52] = 219;
	Sahne[7][53] = 219;
	Sahne[8][51] = 219;
	Sahne[9][51] = 219;
	Sahne[9][52] = 219;
	Sahne[9][53] = 219;
	Sahne[10][51] = 219;
	Sahne[11][51] = 219;
	Sahne[11][52] = 219;
	Sahne[11][53] = 219;
	//R//
	Sahne[7][55] = 219;
	Sahne[7][56] = 219;
	Sahne[7][57] = 219;
	Sahne[7][58] = 219;
	Sahne[8][55] = 219;
	Sahne[8][58] = 219;
	Sahne[9][55] = 219;
	Sahne[9][56] = 219;
	Sahne[9][57] = 219;
	Sahne[9][58] = 219;
	Sahne[10][55] = 219;
	Sahne[10][57] = 219;
	Sahne[11][55] = 219;
	Sahne[11][58] = 219;
}