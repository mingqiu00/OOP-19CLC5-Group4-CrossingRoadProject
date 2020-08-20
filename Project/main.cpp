#include "CGAME.h"
int main()
{
	TextureHolder holder;
	CGAME cg;
	VideoMode vm(800, 600);
	RenderWindow window(vm, "Cross the road");
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	Clock clock;
	while (window.isOpen())
	{
		Time dt = clock.restart();
		// Press Esc to close
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		cg.updatePosPeople(dt.asSeconds());
		cg.updatePosVehicle(dt.asSeconds());
		cg.updatePosAnimal(dt.asSeconds());
		cg.startGame();
		window.clear();
		window.draw(spriteBackground);
		cg.drawGame(window);
		window.display();
	}

	return 0;
}
