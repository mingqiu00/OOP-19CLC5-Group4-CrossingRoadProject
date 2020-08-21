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
MyRandom::MyRandom()
{
	srand(time(NULL));
	ran = rand();
}
int MyRandom::next()
{
	return rand() % RAND_MAX + 0;
}
int MyRandom::next(int x)
{
	return rand() % x + 0;
}
int MyRandom::next(int a, int b)
{
	if (a < b)
		return rand() % (b - a + 1) + a;
	return rand() % (a - b + 1) + b;
}
double MyRandom::nextDouble()
{
	return (double)rand() / RAND_MAX;
}
bool CTRAFFICLIGHT::getLight()
{
	return light;
}
void CTRAFFICLIGHT::changeLight()
{
	while (1 > 0)
	{
		MyRandom r;
		time = r.nextDouble();
		if (light == false) light = true;
		else light = false;
	}
}
void CTRUCK::Stop()
{
	sf::Vector2f temp;
	temp.x = this->Pos().x;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}
