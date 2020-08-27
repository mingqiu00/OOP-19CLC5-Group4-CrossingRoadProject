#include "movable.h"

// Returns the position of the object
sf::Vector2f Movable::getPosition()
{
	return m_rectBox.getPosition();
}
// Sets the position of the object
void  Movable::setPosition(sf::Vector2f transformation)
{
	m_rectBox.setPosition(transformation);
}