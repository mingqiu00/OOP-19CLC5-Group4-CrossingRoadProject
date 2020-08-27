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
	sf::SoundBuffer bufferBird;
	sf::SoundBuffer bufferSnake;
	int speed = 100;
	sf::Sprite m_Sprite;
public:
	CANIMAL() {	}
	void setSpeed(int _speed) { this->speed = _speed; }
	int getSpeed() { return speed; }
	sf::Sprite getSprite() { return m_Sprite; }
	sf::Vector2f Pos() { return m_Sprite.getPosition(); }
	void setPos(float a, float b) { m_Sprite.setPosition(a, b); }
	void Move(float elapsedTime);
	bool checkCollision(sf::FloatRect other);
	virtual void Tell() = 0;
};

class CBIRD : public CANIMAL
{
public:
	CBIRD() 
	{
		if (!bufferBird.loadFromFile("sound/cat.wav"))
			cout << "Can't load cat sound" << endl;
	}
	void spawn()
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bird.png"));
	}
	void Tell();
};

class CSNAKE : public CANIMAL
{
public:
	CSNAKE()
	{
		if (!bufferSnake.loadFromFile("sound/dog.wav"))
			cout << "Can't load dog sound" << endl;
	}
	void spawn()
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/snake.png"));
	}
 	void Tell();
};
#endif
