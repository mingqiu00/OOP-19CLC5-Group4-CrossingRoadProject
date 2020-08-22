
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
	virtual sf::Sprite getSprite() { return m_Sprite; }
	virtual sf::Vector2f Pos();
	void setSpeed(int _speed) { this->speed = _speed; }
	virtual void Move(float elapsedTime) = 0;
	virtual void Stop() = 0;
	virtual void setPos(float a, float b);
	virtual void spawn(float x, float y) = 0;
};
class CCAR : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	void Move(float elapsedTime);
	void spawn(float x, float y);
	void Stop();
};
class CTRUCK : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	void Move(float elapsedTime);
	void spawn(float x, float y);
	void Stop();
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
