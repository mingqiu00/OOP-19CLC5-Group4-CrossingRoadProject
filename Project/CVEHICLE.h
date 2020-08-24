#ifndef _CVEHICLE_H
#define _CVEHICLE_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include "TextureHolder.h"
#include <ctime>
#include <time.h>
using namespace std;
class CVEHICLE
{
protected:
	sf::Sound sound;
	sf::SoundBuffer buffer;
	int speed = 100;
	sf::Sprite m_Sprite;
public:
	virtual sf::Sprite getSprite() { return m_Sprite; }
	void setSpeed(int _speed) { this->speed = _speed; }
	int getSpeed() { return speed; }
	virtual sf::Vector2f Pos();
	virtual void Move(float elapsedTime);
	// virtual void Stop() = 0;
	virtual void setPos(float a, float b);
	// virtual void spawn(float x, float y) = 0;
};
class CCAR : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	// void Stop();
	void spawn(float x,float y);
};
class CTRUCK : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	// void Stop();
	void spawn(float x,float y);
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
