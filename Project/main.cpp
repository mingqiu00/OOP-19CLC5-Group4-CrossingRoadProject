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
	sf::Clock clock;
	sf::Time dt;
	sf::Time elapsed;
	cg.setPosPeople();
	while (window.isOpen())
	{
		elapsed += clock.getElapsedTime();
		dt = clock.getElapsedTime();
		clock.restart();
		if (elapsed.asSeconds() >= 4)
		{
			cg.changeTrafficLight();
			elapsed = seconds(0);
		}
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
		cg.updatePosPeople(event,window);
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
