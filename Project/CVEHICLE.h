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
	void setSpeed(int _speed) { this->speed = _speed; }
	sf::Sprite getSprite() { return m_Sprite; }
	sf::Vector2f Pos();
	void setPos(float a, float b);
	void Move(float elapsedTime);
	// virtual void Stop() = 0;
};
class CCAR : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	// void Stop();
	CCAR();
};
class CTRUCK : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	// void Stop();
	CTRUCK();
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
