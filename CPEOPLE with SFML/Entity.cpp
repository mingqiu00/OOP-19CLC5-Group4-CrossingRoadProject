
#include "Entity.h"

// returns the bounding box of the entity
sf::FloatRect Entity::getBounds()
{
	return m_rectBox.getGlobalBounds();
}

// draws the entity to the window
