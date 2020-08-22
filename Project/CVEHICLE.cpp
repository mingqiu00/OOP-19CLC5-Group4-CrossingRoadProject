#include "CVEHICLE.h"
sf::Vector2f CVEHICLE::Pos()
{
	sf::Vector2f temp = m_Sprite.getPosition();
	return temp;
}

void CVEHICLE::setPos(float a, float b)
{
	sf::Vector2f position;
	position.x = a;
	position.y = b;
	m_Sprite.setPosition(position);
}

void CVEHICLE::Move(float elapsedTime)
{
	m_Sprite.move(speed * elapsedTime, 0);
	if (m_Sprite.getPosition().x > 805)
		setPos(-85, m_Sprite.getPosition().y);
}

CCAR::CCAR()
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/car.png"));
}

CTRUCK::CTRUCK()
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/truck.png"));
}

MyRandom::MyRandom()
{
	CTRAFFICLIGHT l;
	while (true)
	{
		unsigned long seconds = 5;
		timer t;
		t.start();
		while (true) {
			if (t.elapsedTime() >= seconds)
			{
				timer t1;
				t1.start();
				while (true)
				{
					if (t1.elapsedTime() >= seconds)
					{
						break;
					}
					else
					{
						l.setGreen();
						m_Sprite.move(speed * elapsedTime, 0);
						if (m_Sprite.getPosition().x > 805)
							setPos(-85, m_Sprite.getPosition().y);
					}
				}
				break;
			}
			else
			{
				l.setRed();
				this->Stop();
			}
		}
	}
}
bool CTRAFFICLIGHT::getLight()
{
	return light;
}
void CTRUCK::Stop()
{
	sf::Vector2f temp;
	temp.x = this->Pos().x;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}
void CCAR::Stop()
{
	sf::Vector2f temp;
	temp.x = this->Pos().x;
	temp.y = this->Pos().y;
	this->setPos(temp.x, temp.y);
}
void CTRAFFICLIGHT::setGreen()
{
	light = true;
}
void CTRAFFICLIGHT::setRed()
{
	light = false;
}
void CCAR::spawn(float x, float y)
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/car.png"));
	m_Sprite.setPosition(x, y);
}
void CTRUCK::spawn(float x, float y)
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/truck.png"));
	m_Sprite.setPosition(x, y);
}
