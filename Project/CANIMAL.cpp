#include "CANIMAL.h"
sf::Vector2f CANIMAL::Pos()
{
	sf::Vector2f temp = m_Sprite.getPosition();
	return temp;
}
void CANIMAL::setPos(float a, float b)
{
	sf::Vector2f position;
	position.x = a;
	position.y = b;
	m_Sprite.setPosition(position);
}
void CBIRD::Move(float elapsedTime)
{
	sf::Vector2f temp;
	temp.x = this->Pos().x * 100 * elapsedTime;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}
void CSNAKE::Move(float elapsedTime)
{
	sf::Vector2f temp;
	temp.x = this->Pos().x * 100 * elapsedTime;
	temp.y = this->Pos().y ;
	this->setPos(temp.x, temp.y);
}
