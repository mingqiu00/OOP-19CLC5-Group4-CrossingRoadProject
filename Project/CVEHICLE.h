#ifndef _CVEHICLE_H
#define _CVEHICLE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include <ctime>
#include <time.h>

class CTRAFFICLIGHT
{
private:
	sf::Sprite m_Sprite;
	friend class CCAR;
	friend class CTRUCK;
	bool light = true; //true: green, false: red
public:
	CTRAFFICLIGHT()	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/green.png"));
	}
	sf::Sprite getSprite() { return m_Sprite; }
	bool getLight() { return light; }
	void setPos(float a, float b) { m_Sprite.setPosition(a, b); }
	void setRed(float a, float b) {
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/red.png"));
		setPos(a, b);
		light = false;
	}
	void setGreen(float a, float b) {
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/green.png"));
		setPos(a, b);
		light = true;
	}
};

class CVEHICLE
{
protected:
	sf::Sound sound;
	sf::SoundBuffer buffer;
	int speed = 100;
	sf::Sprite m_Sprite;
public:
	void setSpeed(int _speed) { this->speed = _speed; }
	int getSpeed() { return speed; }
	sf::Sprite getSprite() { return m_Sprite; }
	sf::Vector2f Pos() { return m_Sprite.getPosition(); }
	void setPos(float a, float b) { m_Sprite.setPosition(a, b); }
	void Stop();
	void Move(float elapsedTime, CTRAFFICLIGHT& light);
	void CrashSound ();
};

class CCAR : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	CCAR() {
		m_Sprite = Sprite(TextureHolder::GetTexture(
  	"graphics/car.png"));
	}
};

class CTRUCK : public CVEHICLE
{
	friend class TRAFFICLIGHT;
public:
	CTRUCK() {
		m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/truck.png"));
	}
};

#endif
