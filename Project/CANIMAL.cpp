#include "CANIMAL.h"
void CANIMAL::Move(float elapsedTime)
{
	m_Sprite.move(-speed * elapsedTime, 0);
		if (m_Sprite.getPosition().x < -80)
			setPos(800, m_Sprite.getPosition().y);
}
bool CANIMAL::checkCollision(CPEOPLE cn) {
	return (Collision::PixelPerfectTest(m_Sprite, cn.m_rectBox));
}
//void CSNAKE::Tell()
//{
//	sound.setBuffer(bufferSnake);
//	sound.setVolume(50.f);
//	sound.play();
//}
//
//void CBIRD::Tell()
//{
//	sound.setBuffer(bufferBird);
//	sound.setVolume(50.f);
//	sound.play();
//}
