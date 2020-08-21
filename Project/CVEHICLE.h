#ifndef _CVEHICLE_H
#define _CVEHICLE_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace std;
class CVEHICLE
{
protected:
	int speed = 100;
	sf::Sprite m_Sprite;
public:
	virtual sf::Sprite getSprite() { return m_Sprite; }
	virtual sf::Vector2f Pos();
	virtual void Move(float elapsedTime);
	// virtual void Stop() = 0;
	virtual void setPos(float a, float b);
	virtual void spawn(float x, float y) = 0;
};
class CCAR : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	// void Stop();
};
class CTRUCK : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	// void Stop();
};
class CTRAFFICLIGHT
{
	friend class CCAR;
	friend class CTRUCK;
	bool light; //true: green, false: red
	float time;
public:
	bool getLight();
	void changeLight();
};
class MyRandom
{
	int ran;
public:
	MyRandom();
	int next();
	int next(int x);
	int next(int a, int b);
	double nextDouble();
};
#endif
