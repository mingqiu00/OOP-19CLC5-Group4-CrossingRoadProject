#include "CGAME.h"

CGAME::CGAME()
{

}

void CGAME::drawGame()
{

}

CGAME::~CGAME()
{
	
}

CPEOPLE CGAME::getPeople()
{
	return cn;
}

CVEHICLE* CGAME::getVehicle()
{
	float max_d = d(axt[0].getPosition(), cn.getPosition();
	for (int i = 1; i < axt.size(); ++i)
	{
		if(d(axt[i].getPosition(), cn.getPosition())>)
	}
	for (int i = 0; i < axh.size(); ++i)
	{

	}
}

CANIMAL* CGAME::getAnimal()
{

}
void CGAME::updatePosPeople(float elapsedTime)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		cn.Up(elapsedTime);
	if (Keyboard::isKeyPressed(Keyboard::S))
		cn.Down(elapsedTime);
	if (Keyboard::isKeyPressed(Keyboard::A))
		cn.Left(elapsedTime);
	if (Keyboard::isKeyPressed(Keyboard::D))
		cn.Right(elapsedTime);
}
void CGAME::updatePosVehicle(float elapsedTime)
{
	for (int i = 0;i < axh.size();i++)
	{
		axh[i].Move(elapsedTime);
	}
	for (int i = 0;i < axt.size();i++)
	{
		axt[i].Move(elapsedTime);
	}
}
void CGAME::updatePosAnimal(float elapsedTime)
{
	for (int i = 0;i < ar.size();i++)
	{
		ar[i].Move(elapsedTime);
	}
	for (int i = 0;i < axt.size();i++)
	{
		ac[i].Move(elapsedTime);
	}
}