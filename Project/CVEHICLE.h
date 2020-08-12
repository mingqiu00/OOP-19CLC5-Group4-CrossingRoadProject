#ifndef _CVEHICLE_H
#define _CVEHICLE_H
#include <iostream>
#include<SFML/Graphics.hpp>
using namespace std;
class CVEHICLE
{
	sf::Sprite m_Sprite;
public:
    virtual sf::Sprite getSprite () {return m_Sprite;}
	virtual sf::Vector2f Pos();
	virtual void Move(float elapsedTime) = 0;
	virtual void setPos(float a, float b);
};
class CCAR : public CVEHICLE
{
public:
	void Move(float elapsedTime);
};
class CTRUCK : public CVEHICLE
{
public:
	void Move(float elapsedTime);
};
#endif 

