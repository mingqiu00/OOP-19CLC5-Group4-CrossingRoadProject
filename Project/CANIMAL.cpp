#include "CANIMAL.h"
sf::Vector2f CANIMAL::Pos()
{
	sf::Vector2f temp = animal.getPosition();
	return temp;
}
void CANIMAL::setPos(float a, float b)
{
	sf::Vector2f position;
	position.x = a;
	position.y = b;
	animal.setPosition(position);
}
void CBIRD::Move(float elapsedTime)
{
	sf::Vector2f temp;
	temp.x = this->Pos().x * 100 * elapsedTime;
	temp.y = this->Pos().y * 100 * elapsedTime;
	this->setPos(temp.x, temp.y);
}
void CSNAKE::Move(float elapsedTime)
{
	sf::Vector2f temp;
	temp.x = this->Pos().x * 100 * elapsedTime;
	temp.y = this->Pos().y * 100 * elapsedTime;
	this->setPos(temp.x, temp.y);
}