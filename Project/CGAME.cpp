#include "CGAME.h"

CGAME::CGAME()
{
	for (int i = 0, float x = 1.0, y = 1.0; i < 5; ++i, x+=2.0)
		{
			CTRUCK truck; CCAR car; CBIRD bird; CSNAKE snake;
			truck.setPos(x, y);
			axt.push_back(truck);
			car.setPos(x + 2.0, y + 2.0);
			axh.push_back(car);
			bird.setPos(x + 4.0, y + 4.0);
			ac.push_back(bird);
			snake.setPos(x + 6.0, y + 6.0);
			ar.push_back(snake);
		}
}

void CGAME::drawGame()
{
	for (int i = 0; i < axt.size(); ++i)
			window.draw(axt[i]);
		for (int i = 0; i < axh.size(); ++i)
			window.draw(axh[i]);
		for (int i = 0; i < ac.size(); ++i)
			window.draw(ac[i]);
		for (int i = 0; i < ar.size(); ++i)
			window.draw(ar[i]);
		window.draw(cn);
}

CGAME::~CGAME() = default;

CPEOPLE CGAME::getPeople()
{
	return cn;
}

CVEHICLE* CGAME::getVehicle()
{
	float max_d_car = d(axt[0].Pos(), cn.Pos()),
			max_d_truck = d(axh[0].Pos(), cn.Pos());
		CCAR* closest_car = &axh[0]; CTRUCK* closest_truck = &axt[0];
		for (int i = 1; i < axt.size(); ++i)
		{
			if (d(axt[i].Pos(), cn.Pos()) > max_d_truck)
				 closest_truck = &axt[i];
		}
		for (int i = 0; i < axh.size(); ++i)
		{
			if (d(axh[i].Pos(), cn.Pos()) > max_d_car)
				closest_car = &axh[i];
		}
		if (max_d_truck > max_d_car) return closest_truck;
		return closest_car;
}

CANIMAL* CGAME::getAnimal()
{
	float max_d_bird = d(ac[0].Pos(), cn.Pos()),
			max_d_snake= d(ar[0].Pos(), cn.Pos());
		CBIRD* closest_bird = &ac[0]; CSNAKE* closest_snake = &ar[0];
		for (int i = 1; i < ac.size(); ++i)
		{
			if (d(ac[i].Pos(), cn.Pos()) > max_d_bird)
				 closest_bird = &ac[i];
		}
		for (int i = 0; i < ar.size(); ++i)
		{
			if (d(ar[i].Pos(), cn.Pos()) > max_d_snake)
				 closest_snake = &ar[i];
		}
		if (max_d_bird > max_d_snake) return closest_bird;
		return closest_snake;
}

void CGAME::resetGame()
{
	axt.clear();
	axh.clear();
	ac.clear();
	ar.clear();
	cn.setPos(0, 0);
	for (int i = 0, float x = 1.0, y = 1.0; i < 5; ++i, x += 2.0)
	{
		CTRUCK truck; CCAR car; CBIRD bird; CSNAKE snake;
		truck.setPos(x, y);
		axt.push_back(truck);
		car.setPos(x + 2.0, y + 2.0);
		axh.push_back(car);
		bird.setPos(x + 4.0, y + 4.0);
		ac.push_back(bird);
		snake.setPos(x + 6.0, y + 6.0);
		ar.push_back(snake);
	}
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
void CGAME::loadGame()
{
	ifstream fin;
	string filename;
	cout << "Input file's name to load ";
	getline(cin, filename);
	fin.open(filename);
	if (!fin.is_open())
		cout << "Can't open file ";
	else
	{
		float x, y;
		fin >> x >> y;
		cn.setPos(x, y);
		for (int i = 0;i < axt.size();i++)
		{
			fin >> x >> y;
			axt[i].setPos(x, y);
		}
		for (int i = 0;i < axh.size();i++)
		{
			fin >> x >> y;
			axh[i].setPos(x, y);
		}
		for (int i = 0;i < ac.size();i++)
		{
			fin >> x >> y;
			ac[i].setPos(x, y);
		}
		for (int i = 0;i < ar.size();i++)
		{
			fin >> x >> y;
			ar[i].setPos(x, y);
		}
		fin.close();
	}
}
void CGAME::saveGame()
{
	ofstream fout;
	string filename;
	cout << "Input file's name to save ";
	getline(cin, filename);
	fout.open(filename);
	if (!fout.is_open())
		cout << "Can't create file ";
	else
	{
		fout << cn.getSprite().getPosition().x << " " << cn.getSprite().getPosition().y << endl;
		for (int i = 0;i < axt.size();i++)
		{
			fout << axt[i].getSprite().getPosition().x << " " << axt[i].getSprite().getPosition().y << endl;
		}
		for (int i = 0;i < axh.size();i++)
		{
			fout << axh[i].getSprite().getPosition().x << " " << axh[i].getSprite().getPosition().y << endl;
		}
		for (int i = 0;i < ac.size();i++)
		{
			fout << ac[i].getSprite().getPosition().x << " " << ac[i].getSprite().getPosition().y << endl;
		}
		for (int i = 0;i < ar.size();i++)
		{
			fout << ar[i].getSprite().getPosition().x << " " << ar[i].getSprite().getPosition().y;
			if (i != ar.size() - 1)
				fout << endl;
		}
		fout.close();
	}
}
