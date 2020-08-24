#include "CANIMAL.h"

void CANIMAL::Move(float elapsedTime)
{
	m_Sprite.move(-speed * elapsedTime, 0);
		if (m_Sprite.getPosition().x < -80)
			setPos(800, m_Sprite.getPosition().y);
}

void CSNAKE::Tell()
{
	if (buffer.loadFromFile("sound/dog.wav"))
	{
		sound.setBuffer(buffer);
		sound.setVolume(100.f);
		sound.play();
		sf::sleep(sf::seconds(2.0));
	}
}

void CBIRD::Tell()
{
	if (buffer.loadFromFile("sound/cat.wav"))
	{
		sound.setBuffer(buffer);
		sound.setVolume(100.f);
		sound.play();
		sf::sleep(sf::seconds(2.0));
	}
}
