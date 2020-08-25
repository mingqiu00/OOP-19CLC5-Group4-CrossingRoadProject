#ifndef _CANIMAL_H
#define _CANIMAL_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"

class CANIMAL
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
	void Move(float elapsedTime);
	virtual void Tell() = 0;
};

class CBIRD : public CANIMAL
{
public:
	void spawn(float x, float y)
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bird.png"));
		m_Sprite.setPosition(x, y);
	}
	void Tell();
};

class CSNAKE : public CANIMAL
{
public:
	void spawn(float x, float y)
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/snake.png"));
		m_Sprite.setPosition(x, y);
	}
 	void Tell();
};
#endif
