/*Автор: Фролов Дмитрий*/
#include "pch.h"
#include <iostream>
#include <time.h>
#include <math.h>



using namespace std;

const int N = 4;

int game_place[N][N];


void InitGamePlace();

void MixGameplace();

void ShowGamePlace();
bool GameWin();
void GamePlay();

int main()
{
	setlocale(LC_ALL, "rus");

	InitGamePlace();
	cout << "Пример поля для победы " << endl;
	ShowGamePlace();

	cout << "---------------------------------" << endl;

	MixGameplace();
	cout << "Наше игровое поле " << endl;
	ShowGamePlace();
	GameWin();
	GamePlay();
	
}

void InitGamePlace()
{
	int k =0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			game_place[i][j] = k;
			k++;
		}
	}
}

void MixGameplace()
{
	int x1,y2,y1,x2,temp;
	srand(time(0));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			x1 = rand() % 3;
			y1 = rand() % 3;
			x2 = rand() % 3;
			y2 = rand() % 3;
			temp = game_place[x1][y1];
			game_place[x1][y1] = game_place[x2][y2];
			game_place[x2][y2] = temp;
		}
	}
}

void ShowGamePlace()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << game_place[i][j] << " \t| ";
		}
		cout << endl;
	}
}

bool GameWin()
{
	int k = 0;
	int game_win[N][N] = { {0,1,2,3}, {4,5,6,7} ,{8,9,10,11} ,{12,13,14,15} };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (game_place[i][j] == game_win[i][j])
			{
				k++;
			}
		}
	}
	if (k == 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GamePlay()
{
		do
		{ 
		int temp;
		enter:

		cout << "Введите координаты нулевой ячейки (строку и столбец от 0 до 3) " << endl;
		int a, b, c, d,h;
		cin >> a; cin >> b;
		cout << "Введите координаты  ячейки на которую будем менять (строку и столбец от 0 до 3) " << endl;
		cin >> c; cin >> d;

		
		if (a < 0 || a>4 || b < 0 || b>4 || c < 0 || c>4 || d < 0 || d>4)
		{
			goto enter;
		}

		if (game_place[a][b] != 0)
		{
			cout << "Введенные координаты не принадлежат ячейки с нулевым значением " << endl;
			goto enter;
		}
		h = abs((a + b) - (c + d));

		
		if(h!=1)
		{
			cout << "Введенные координаты не принадлежат соседней с нулем ячейки " << endl;
			goto enter;
		}
		
		temp=game_place[a][b];
		 game_place[a][b] = game_place[c][d];
		 game_place[c][d] = temp;

		 system("cls");
		 cout << "---------------------------------" << endl;
		 cout << "После замены " << endl;
		 ShowGamePlace();


		} while (!GameWin());
}
