#ifndef _CANIMAL_H
#define _CANIMAL_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace std;
class CANIMAL
{
	sf::Sprite m_Sprite;
public:
   	virtual sf::Sprite getSprite () {return m_Sprite;}
	virtual sf::Vector2f Pos();
	virtual void Move(float elapsedTime) = 0;
	virtual void setPos(float a, float b); 
	virtual void Tell() = 0;
};
class CBIRD : public CANIMAL
{
public:
	void Move(float elapsedTime);
	void Tell();
	void spawn(float x, float y);
};
class CSNAKE : public CANIMAL
{
public:
	void Move(float elapsedTime);
	void Tell();
	void spawn(float x, float y);
};
#endif 

