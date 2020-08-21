#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

// Base class for rectangular objects
class Entity
{
public:
	sf::FloatRect getBounds();		// Provides a FloactRect of the boundries
	// Draws the rectangle on the given window
	void draw(sf::RenderWindow& window) {
		window.draw(m_rectBox);
	}
protected:
	sf::RectangleShape m_rectBox;	// The basic shape of the entity		
};
#endif