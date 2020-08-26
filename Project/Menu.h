#pragma once
#include "SFML/Graphics.hpp"
#include "CGAME.h"
#define MAX 3

class Menu
{
public:
	Menu(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getSelected() { return selected; }
    void processMenu(RenderWindow& window,int& state,Event &event,int& selection)
	{
		switch (event.type)
		{
		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Up:
				MoveUp();
				break;

			case Keyboard::Down:
				MoveDown();
				break;

			case Keyboard::Return:
				switch (selected)
				{
				case 0:
					state = 0;
					break;
				case 1:
					selection = 1;
					state = 0;
					break;
				case 2:
					window.close();
					break;
				}

				break;
			}

			break;
		case Event::Closed:
			window.close();

			break;

		}
	}

private:
	int selected;
	Font font;
	Text menu[MAX];

};