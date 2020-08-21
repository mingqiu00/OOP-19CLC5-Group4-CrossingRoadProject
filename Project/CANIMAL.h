#ifndef _CANIMAL_H
#define _CANIMAL_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace std;
class CANIMAL
{
protected:
	int speed = 100;
	sf::Sprite m_Sprite;
public:
  virtual sf::Sprite getSprite () {return m_Sprite;}
	void setSpeed(int _speed) { this->speed = _speed; }
	virtual sf::Vector2f Pos();
	virtual void Move(float elapsedTime);
	virtual void setPos(float a, float b);
	// virtual void Tell() = 0;
	virtual void spawn(float x, float y) = 0;
};
class CBIRD : public CANIMAL
{
public:
	// void Tell();
	void spawn(float x, float y);
};
class CSNAKE : public CANIMAL
{
public:
	// void Tell();
	void spawn(float x, float y);
};
#endif
