#ifndef _CANIMAL_H
#define _CANIMAL_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "TextureHolder.h"
using namespace std;
class CANIMAL
{
protected:
	int speed = 100;
	sf::Sprite m_Sprite;
public:
	void setSpeed(int _speed) { this->speed = _speed; }
	int getSpeed() { return speed; }
	sf::Sprite getSprite() { return m_Sprite; }
	sf::Vector2f Pos();
	void setPos(float a, float b);
	void Move(float elapsedTime);
	virtual void Tell() = 0;
};
class CBIRD : public CANIMAL
{
public:
	CBIRD();
	void Tell();
};
class CSNAKE : public CANIMAL
{
public:
	CSNAKE();
	void Tell();
};
#endif
