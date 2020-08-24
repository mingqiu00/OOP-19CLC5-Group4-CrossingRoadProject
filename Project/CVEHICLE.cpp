#include "CVEHICLE.h"

void CVEHICLE::Stop()
{
	sf::Vector2f temp;
	temp.x = this->Pos().x;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}

void CVEHICLE::Move(float elapsedTime, CTRAFFICLIGHT& light)
{
	if (light.getLight())
	{
		m_Sprite.move(speed * elapsedTime, 0);
		if (m_Sprite.getPosition().x > 805)
			setPos(-85, m_Sprite.getPosition().y);
	}
	if (!light.getLight()) this->Stop();
}

void CVEHICLE::CrashSound()
{
	if (buffer.loadFromFile("sound/crash.wav"))
	{
		sound.setBuffer(buffer);
		sound.setVolume(100.f);
		sound.play();
		sf::sleep(sf::seconds(2.0));
	}
}
