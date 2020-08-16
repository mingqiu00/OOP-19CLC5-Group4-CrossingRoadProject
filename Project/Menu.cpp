#include "Menu.h"
void gotoXY(int pX, int pY)
{
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void txtColor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

void printrect(int x1, int y1, int x2, int y2)
{
	char HORZ = 196;
	char VERT = 179;
	char TL = 218;
	char TM = 194;
	char TR = 191;
	char BL = 192;
	char BM = 193;
	char BR = 217;
	int i;
	gotoXY(x1, y1);
	cout << TL;
	gotoXY(x2, y1);
	cout << TR;
	gotoXY(x1, y2);
	cout << BL;
	gotoXY(x2, y2);
	cout << BR;
	for (i = x1 + 1; i < x2; i++)
	{
		gotoXY(i, y1);
		cout << HORZ;
	}
	for (i = x1 + 1; i < x2; i++)
	{
		gotoXY(i, y2);
		cout << HORZ;
	}
	for (i = y1 + 1; i < y2; i++)
	{
		gotoXY(x1, i);
		cout << VERT;
	}
	for (i = y1 + 1; i < y2; i++)
	{
		gotoXY(x2, i);
		cout << VERT;
	}
}
void printMainMenu(int selection, int n, char* menu_items[])
{
	for (int i = 0; i <= n - 1; i++)
	{
		txtColor(11);
		gotoXY(50, i + 10);
		if (i == selection)
			txtColor(12);
		cout << menu_items[i];
	}
}
int selectMainMenu(int n, char* menu_items[])
{
	int selection = 0;
	while (1)
	{
		int move = _getch();
		if (move == 80)
		{
			selection++;
			if (selection == n)
				selection = 0;
			printMainMenu(selection, n, menu_items);
		}
		if (move == 72)
		{
			selection--;
			if (selection == -1)
				selection = n - 1;
			printMainMenu(selection, n, menu_items);
		}
		if (move == 13)
			return selection;
	}
}
void Menu(CGAME cg)
{
	char* menu_items[] = { "1. New Game","2. Load Game","3. Settings" };
	printrect(45, 9, 65, 13);
	for (int i = 0;i < 3;i++)
	{
		if (i == 0) txtColor(12);
		else txtColor(11);
		gotoXY(50, i + 10);
		cout << menu_items[i];
	}
	int selection = selectMainMenu(3, menu_items);
	switch (selection)
	{
	case 1:
		cg.startGame();
		break;
	case 2:
		cg.loadGame();
		break;
	//case 3:
		//cg.settings();
	}
}