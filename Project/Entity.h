#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

// Base class for rectangular objects
class Entity
{
public:
	sf::FloatRect getBounds();		// Provides a FloactRect of the boundries
	void draw(sf::RenderWindow&);
	sf::Sprite m_rectBox;	// Draws the rectangle on the given window
protected:
		// The basic shape of the entity		
};
#endif