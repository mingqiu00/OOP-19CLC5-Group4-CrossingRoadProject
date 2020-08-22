#ifndef CPEOPLE_H
#define CPEOPLE_H

#include <SFML/Graphics.hpp>
#include "Movable.h"

// Creates a player object that can be controlled by a user
class CPEOPLE : public Movable
{
public:
	// Constructor
	CPEOPLE();

	// Returns the lives the player has remaining
	int getLivesLeft();

	// Returns the number of moves the player has took
	int getMovesTaken();

	// Decrements the number of lives the player has left
	void loseLife();

	// Checks for user input and makes the appropiate move if possible
	void checkMovement(sf::Event& event, sf::RenderWindow& window);

	// Updates the players position
	void update(sf::Event& event, sf::RenderWindow& window);
	
	void setPos(float x,float y) {
		m_rectBox.setPosition(x, y);
	}
	RectangleShape getBox() { return m_rectBox; }

private:
	int m_iLivesLeft;	// The number of lives the player has left
	int m_iMoves;		// The number of moves the player has made
	sf::Clock moveCooldownClock; // Keeps track of the cooldown of when the player cannot move
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	sf::Texture texPlayerTexture; // Holds the texture for the player
};

#endif