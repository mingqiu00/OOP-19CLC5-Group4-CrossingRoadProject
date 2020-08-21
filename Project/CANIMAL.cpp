#include "CANIMAL.h"
sf::Vector2f CANIMAL::Pos()
{
	sf::Vector2f temp = m_Sprite.getPosition();
	return temp;
}
void CANIMAL::setPos(float a, float b)
{
	sf::Vector2f position;
	position.x = a;
	position.y = b;
	m_Sprite.setPosition(position);
}
void CANIMAL::Move(float elapsedTime)
{
	m_Sprite.move(-speed * elapsedTime, 0);
		if (m_Sprite.getPosition().x < -80)
			setPos(800, m_Sprite.getPosition().y);
}
void CSNAKE::spawn(float x, float y)
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/snake.png"));
		m_Sprite.setPosition(x, y);
}
void CBIRD::spawn(float x, float y)
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bird.png"));
		m_Sprite.setPosition(x, y);
}
