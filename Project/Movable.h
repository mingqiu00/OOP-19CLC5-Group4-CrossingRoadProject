#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

// A basic class for movable rectangular objects
class Movable : public Entity
{
public:
	// Returns the x,y coordinates of the object
	sf::Vector2f getPosition();

	// sets the positon of the object
	void setPosition(sf::Vector2f transformation);
};

#endif