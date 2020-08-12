#include "CVEHICLE.h"
sf::Vector2f CVEHICLE::Pos()
{
	sf::Vector2f temp = m_Sprite.getPosition();
	return temp;
}
void CVEHICLE::setPos(float a, float b)
{
	sf::Vector2f position;
	position.x = a;
	position.y = b;
	m_Sprite.setPosition(position);
}
void CCAR::Move(float elapsedTime)
{
	sf::Vector2f temp;
	temp.x = this->Pos().x * 100 * elapsedTime;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}
void CTRUCK::Move(float elapsedTime)
{
	sf::Vector2f temp;
	temp.x = this->Pos().x * 100 * elapsedTime;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}
