
#ifndef _CVEHICLE_H
#define _CVEHICLE_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include <cstdlib>
#include "TextureHolder.h"
#include <ctime>
#include <time.h>
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
public:
	bool getLight();
	void setRed();
	void setGreen();
};
class timer
{
private:
	unsigned long begTime;
public:
	void start() {
		begTime = clock();
	}

	unsigned long elapsedTime() {
		return ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC;
	}

	bool isTimeout(unsigned long seconds) {
		return seconds >= elapsedTime();
	}
};
#endif
