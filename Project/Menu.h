#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "CGAME.h"
using namespace std;
void gotoXY(int pX, int pY);
void txtColor(int x);
void setFontSize(int FontSize);
void printrect(int x1, int y1, int x2, int y2);
void printMainMenu(int selection, int n, char* menu_items[]);
int selectMainMenu(int n, char* menu_items[]);
void Menu(CGAME cg);