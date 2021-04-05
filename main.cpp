#include <iostream>
#include <locale.h>
#include <Windows.h>
using namespace std;

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

char board[25] = { '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-' };

void clear()
{
	for (int i = 0; i < 20; i++)
	{
		cout << "" << endl;
	}
}

void print_board()
{
	SetColor(15, 0);
	{
		cout << "    Игровая доска    ";
		cout << "" << endl;
		cout << "---------------------" << endl;
		cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " | " << board[3] << " | " << board[4] << " |" << endl;
		cout << "---------------------" << endl;
		cout << "| " << board[5] << " | " << board[6] << " | " << board[7] << " | " << board[8] << " | " << board[9] << " |" << endl;
		cout << "---------------------" << endl;
		cout << "| " << board[10] << " | " << board[11] << " | " << board[12] << " | " << board[13] << " | " << board[14] << " |" << endl;
		cout << "---------------------" << endl;
		cout << "| " << board[15] << " | " << board[16] << " | " << board[17] << " | " << board[18] << " | " << board[19] << " |" << endl;
		cout << "---------------------" << endl;
		cout << "| " << board[20] << " | " << board[21] << " | " << board[22] << " | " << board[23] << " | " << board[24] << " |" << endl;
		cout << "---------------------" << endl;
	}
}

int get_move()
{
	SetColor(15, 0);
	{
		cout << "      Диапозон       ";
		cout << "" << endl;
		cout << "---------------------" << endl;
		cout << "| 1 | 2 | 3 | 4 | 5 |" << endl;
		cout << "---------------------" << endl;
		cout << "| 6 | 7 | 8 | 9 | 10|" << endl;
		cout << "---------------------" << endl;
		cout << "| 11| 12| 13| 14| 15|" << endl;
		cout << "---------------------" << endl;
		cout << "| 16| 17| 18| 19| 20|" << endl;
		cout << "---------------------" << endl;
		cout << "| 21| 22| 23| 24| 25|" << endl;
		cout << "---------------------" << endl;
		cout << "" << endl;
	}

	print_board();
	cout << "Ваш ход: ";

	int move;
	cin >> move;
	while (move > 25 || move < 1 || board[move - 1] != '-')
	{
		SetColor(15, 4);
		{
			cout << "Вы вышли за пределы поля или сходили на занятую клетку. Пожалуйста, переходите: ";
		}
		cin >> move;
	}
	return move;
}


int main()
{
	setlocale(0, "");
	for (int i = 0; i < 26; i++)
	{
		clear();
		int move = get_move();
		cout << "Вы ходили сюда: " << move << endl;
		if (i % 2 == 0)
		{
				board[move - 1] = 'X';
		}
		else
		{
			board[move - 1] = '0';
		}
	}
	cout << "";
	print_board();
	system("pause");
	return 0;
}