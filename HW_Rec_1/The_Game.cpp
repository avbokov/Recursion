#include<iostream>
#include<conio.h>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

const int ROWS = 11;
const int COLS = 35;

void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS); // рисуем и заполняем поле
void Print(char arr[ROWS][COLS], const int ROWS, const int COLS); // выводим текущее состояния поля на экран
void Move(char arr[ROWS][COLS], const int ROWS, const int COLS, char player); // ход игрока
void CheckWin(char arr[ROWS][COLS], const int ROWS, const int COLS, char player); // проверка на победу

void main()
{
	setlocale(LC_ALL, "Russian");

	char arr[ROWS][COLS];
	char key;
	char player = 'X';
		
	system("cls");
		
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
		
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
		{
			cout << endl;
			cout << "Ничья! Победила дружба!" << endl << endl;
			cout << "Для новой партии нажмите любую клавишу..." << endl;
			_getch(); main();
		}
		cout << endl;
		cout << "Ход игрока: " << player;
		cout << endl;
		Move(arr, ROWS, COLS, player);
		CheckWin(arr, ROWS, COLS, player);
		if (player == 'X') player = '0';
		else if (player == '0') player = 'X';
	}
}

void Move(char arr[ROWS][COLS], const int ROWS, const int COLS, char player)
{
		char key;
		key = _getch();
		
		switch (key)
		{
		case '7':
			if (arr[1][2] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[1][2] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '8':
			if (arr[1][8] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[1][8] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '9':
			if (arr[1][14] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[1][14] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '4':
			if (arr[5][2] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[5][2] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '5':
			if (arr[5][8] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[5][8] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '6':
			if (arr[5][14] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[5][14] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '1':
			if (arr[9][2] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[9][2] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '2':
			if (arr[9][8] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[9][8] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;
		case '3':
			if (arr[9][14] != 32)
			{
				cout << endl;
				cout << "Клетка занята! Попробуйте в другую клетку.\n";
				Move(arr, ROWS, COLS, player);
			}
			else
			{
				arr[9][14] = player;
				system("cls");
				Print(arr, ROWS, COLS);
			}
			break;

		default: if (key != -32)
			{
				cout << endl;
				cout << "Error!\n";
				Move(arr, ROWS, COLS, player);
			}
		}
}

void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = 32;
			if (i == 3 || i == 7) arr[i][j] = '--';
			if (j == 5 || j == 11 || j == 23 || j == 29) arr[i][j] = '|';
		}
	}
	arr[3][17] = ' '; arr[7][17] = ' '; // заполняем памятку
	arr[1][20] = '7'; arr[1][26] = '8'; arr[1][32] = '9';
	arr[5][20] = '4'; arr[5][26] = '5'; arr[5][32] = '6';
	arr[9][20] = '1'; arr[9][26] = '2'; arr[9][32] = '3';
}

void Print(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void CheckWin(char arr[ROWS][COLS], const int ROWS, const int COLS, char player)
{
	if ((arr[1][2] == '0' && arr[1][8] == '0' && arr[1][14] == '0') || (arr[1][2] == 'X' && arr[1][8] == 'X' && arr[1][14] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[5][2] == '0' && arr[5][8] == '0' && arr[5][14] == '0') || (arr[5][2] == 'X' && arr[5][8] == 'X' && arr[5][14] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[9][2] == '0' && arr[9][8] == '0' && arr[9][14] == '0') || (arr[9][2] == 'X' && arr[9][8] == 'X' && arr[9][14] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[1][2] == '0' && arr[5][2] == '0' && arr[9][2] == '0') || (arr[1][2] == 'X' && arr[5][2] == 'X' && arr[9][2] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[1][8] == '0' && arr[5][8] == '0' && arr[9][8] == '0') || (arr[1][8] == 'X' && arr[5][8] == 'X' && arr[9][8] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[1][14] == '0' && arr[5][14] == '0' && arr[9][14] == '0') || (arr[1][14] == 'X' && arr[5][14] == 'X' && arr[9][14] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[1][2] == '0' && arr[5][8] == '0' && arr[9][14] == '0') || (arr[1][2] == 'X' && arr[5][8] == 'X' && arr[9][14] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
	else if ((arr[1][14] == '0' && arr[5][8] == '0' && arr[9][2] == '0') || (arr[1][14] == 'X' && arr[5][8] == 'X' && arr[9][2] == 'X'))
	{
		cout << endl;
		cout << "Победил игрок: " << player << endl << endl;
		cout << "Для новой партии нажмите любую клавишу..." << endl;
		_getch(); main();
	}
}