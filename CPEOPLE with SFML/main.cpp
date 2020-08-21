#include "CPEOPLE.h"
#include "Entity.h"
#include "Movable.h"


int main() {
	srand(time(NULL));
	TextureHolder holder;
	CGAME cg;
	VideoMode vm(960, 540);
	RenderWindow window(vm, "Cross the road");
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.jpg");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	Clock clock;
	sf::RenderWindow window(sf::VideoMode(800, 680), "Cross the street"); // creates the window
	window.setFramerateLimit(60);	// Limits framerate to 60fps
	CPEOPLE cPeople;					// Creates a player
	cPeople.setPosition(sf::Vector2f(375, 625));	//sets the initial player position
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		cPeople.draw(window);
		cPeople.update(event, window);	// Check if the user has requested the player to move
		window.display();
	}
}