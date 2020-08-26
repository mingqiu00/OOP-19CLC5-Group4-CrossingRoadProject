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
bool CVEHICLE::checkCollision(sf::FloatRect other) {
	if (m_Sprite.getGlobalBounds().intersects(other))
		return true;
	else return false;
}
void CVEHICLE::CrashSound()
{
	sound.setBuffer(buffer);
	sound.setVolume(10.f);
	sound.play();
}