#include "Menu.h"
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		cout << "Can't load font";
	}

	menu[0].setFont(font);
	menu[0].setColor(Color::Red);
	menu[0].setStyle(Text::Bold);
	menu[0].setString("New Game");
	menu[0].setPosition(Vector2f(width / 2 - 50, height / (MAX + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(Color::Black);
	menu[1].setStyle(Text::Bold);
	menu[1].setString("Load Game");
	menu[1].setPosition(Vector2f(width / 2 - 50, height / (MAX + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(Color::Black);
	menu[2].setStyle(Text::Bold);
	menu[2].setString("Settings");
	menu[2].setPosition(Vector2f(width / 2 - 50, height / (MAX + 1) * 3));

	selected = 0;
}



void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selected - 1 >= 0)
	{
		menu[selected].setColor(Color::Black);
		selected--;
		menu[selected].setColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selected + 1 < MAX)
	{
		menu[selected].setColor(Color::Black);
		selected++;
		menu[selected].setColor(Color::Red);
	}
}