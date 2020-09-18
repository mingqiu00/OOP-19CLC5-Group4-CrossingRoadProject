#include "CGAME.h"
#include "Menu.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	TextureHolder holder;
	CGAME cg;
	RenderWindow window(VideoMode(800, 600), "CROSS THE ROAD");
	Menu menu(window.getSize().x, window.getSize().y);
	Texture textureBackground;
	Texture menuBackground;
	textureBackground.loadFromFile("graphics/background.png");
	menuBackground.loadFromFile("graphics/road.jpg");
	Sprite spriteBackground;
	Sprite spriteMenuBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	spriteMenuBackground.setTexture(menuBackground);
	spriteMenuBackground.setPosition(0, 0);
	int state = -1;
	int selection = -1;
	bool paused = true;
	Clock clock;
	Time dt;
	Time elapsed;
	while (window.isOpen())
	{
		elapsed += clock.getElapsedTime();
		dt = clock.getElapsedTime();
		clock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			// Process menu
			if (state == -1)
			{
				menu.processMenu(window, state, event, selection);
			}
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (state == 0 && paused)
		{
			if (selection == -1) {
				cg.init();
				cg.setPosPeople();
				state = 1;
			}
			else {
				cg.loadGame();
				if (Keyboard::isKeyPressed(Keyboard::Enter))
					state = 1;

			}
		}
		// Press Space to continue the game
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			state = 1;
			paused = false;
		}
		if (!paused && state == 1)
		{
			if (elapsed.asSeconds() >= 4)
			{
				cg.changeTrafficLight();
				elapsed = seconds(0);
			}
			cg.startGame();
			cg.updatePosPeople(event, window);
			cg.updatePosVehicle(dt.asSeconds());
			cg.updatePosAnimal(dt.asSeconds());
		}
		while (window.pollEvent(event))
		{
			if (cg.save(window, state))
			{
				cg.chooseSave(window, event, paused, state);
			}
			if(cg.pause(window,state))
			{
				cg.playagain(window, event, paused, state);
				selection = -1;
			}
			if (cg.gameOver(window, state))
			{
				cg.playagain(window, event, paused, state);
				selection = -1;
			}
			if (cg.winGame(window, state))
			{
				cg.playagain(window, event, paused, state);
				selection = -1;
			}
		}
		if(state==-1 || state==1)
			window.clear();
		if (state == -1)
		{
			window.draw(spriteMenuBackground);
			menu.draw(window);
		}
		if (state == 1)
		{
			window.draw(spriteBackground);
			cg.drawGame(window);
		}
		if(state==-1||state==1)
			window.display();
	}
}