#include "CPEOPLE.h"

// Creates a player object that can be controlled by a user
CPEOPLE::CPEOPLE()
{
	// Set initial values
	m_iMoves = 0;
	m_iLivesLeft = 3;

	// Load the CPEOPLE texture
	texPlayerTexture.loadFromFile("graphics/ninja.png");
	m_rectBox.setTexture(texPlayerTexture);

}

int CPEOPLE::getLivesLeft() { return m_iLivesLeft; }

int CPEOPLE::getMovesTaken() { return m_iMoves; }

void CPEOPLE::loseLife() { m_iLivesLeft--; }


void CPEOPLE::moveLeft()
{
	setPosition(getPosition() + sf::Vector2f(-20, 0));
}
void CPEOPLE::moveRight()
{
	setPosition(getPosition() + sf::Vector2f(20, 0));
}
void CPEOPLE::moveUp()
{
	setPosition(getPosition() + sf::Vector2f(0, -20));
}
void CPEOPLE::moveDown()
{
	setPosition(getPosition() + sf::Vector2f(0, 20));
}

// Check if there is a key input corisponding to a movement (arrow keys)
// Check that the is not an active cooldown
// Check that after performing the move the CPEOPLE will be completely on the screen
// if all are true perform the move, increment the move counter variable, start the cooldown
void CPEOPLE::checkMovement(sf::Event& event, sf::RenderWindow& window)
{
	sf::Time cooldown = sf::seconds(0.1f); // cooldown of 0.25 seconds
	if (event.type == sf::Event::KeyPressed && moveCooldownClock.getElapsedTime() > cooldown) // check for keypress and cooldown

	{
		if (event.key.code == sf::Keyboard::Left)
		{
			moveLeft();
			moveCooldownClock.restart();
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			moveRight();
			moveCooldownClock.restart();
		}
		else if (event.key.code == sf::Keyboard::Up)
		{
			moveUp();
			moveCooldownClock.restart();
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			moveDown();
			moveCooldownClock.restart();
		}
	}
}
// Updates the CPEOPLEs position
void CPEOPLE::update(sf::Event& event, sf::RenderWindow& window)
{
	checkMovement(event, window);
}