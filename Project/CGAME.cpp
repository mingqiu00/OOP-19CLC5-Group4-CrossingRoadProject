#include "CGAME.h"

CGAME::CGAME()
{
	level = 1;
	for (int i = 0; i < 5; ++i)
	{
		CCAR car;
		car.spawn(180 * i, 70);
		axh.push_back(car);
		CBIRD bird;
		bird.spawn(180 * i, 180);
		ac.push_back(bird);
		CTRUCK truck;
		truck.spawn(180 * i, 300);
		axt.push_back(truck);
		CSNAKE snake;
		snake.spawn(180 * i, 420);
		ar.push_back(snake);
	}
}

void CGAME::drawGame(sf::RenderWindow &window)
{
	cn.draw(window);
	for (int i = 0; i < axt.size(); ++i)
		window.draw(axt[i].getSprite());
	for (int i = 0; i < ac.size(); ++i)
		window.draw(ac[i].getSprite());
	for (int i = 0; i < axh.size(); ++i)
		window.draw(axh[i].getSprite());
	for (int i = 0; i < ar.size(); ++i)
		window.draw(ar[i].getSprite());
}

CPEOPLE CGAME::getPeople() {
	return cn;
}

// CVEHICLE* CGAME::getVehicle()
// {
	// float max_d_car = d(axt[0].Pos(), cn.Pos()),
			// max_d_truck = d(axh[0].Pos(), cn.Pos());
		// CCAR* closest_car = &axh[0]; CTRUCK* closest_truck = &axt[0];
		// for (int i = 1; i < axt.size(); ++i)
		// {
			// if (d(axt[i].Pos(), cn.Pos()) > max_d_truck)
				 // closest_truck = &axt[i];
		// }
		// for (int i = 0; i < axh.size(); ++i)
		// {
			// if (d(axh[i].Pos(), cn.Pos()) > max_d_car)
				// closest_car = &axh[i];
		// }
		// if (max_d_truck > max_d_car) return closest_truck;
		// return closest_car;
// }

// CANIMAL* CGAME::getAnimal()
// {
	// float max_d_bird = d(ac[0].Pos(), cn.Pos()),
			// max_d_snake= d(ar[0].Pos(), cn.Pos());
		// CBIRD* closest_bird = &ac[0]; CSNAKE* closest_snake = &ar[0];
		// for (int i = 1; i < ac.size(); ++i)
		// {
			// if (d(ac[i].Pos(), cn.Pos()) > max_d_bird)
				 // closest_bird = &ac[i];
		// }
		// for (int i = 0; i < ar.size(); ++i)
		// {
			// if (d(ar[i].Pos(), cn.Pos()) > max_d_snake)
				 // closest_snake = &ar[i];
		// }
		// if (max_d_bird > max_d_snake) return closest_bird;
		// return closest_snake;
// }

void CGAME::startGame()
{
	if (level > MAX_LEVEL) return; //cho nay chua xong, neu pha dao thi in ra man hinh thong bao
	// if (cn.Pos().y < 50)
	// {
		// ++level;
		// cn.setPos(400, 530);
		// for (int i = 0; i < axt.size(); ++i)
			// axt[i].setSpeed(level * 50);
		// for (int i = 0; i < ac.size(); ++i)
			// ac[i].setSpeed(level * 50);
		// for (int i = 0; i < axh.size(); ++i)
			// axh[i].setSpeed(level * 50);
		// for (int i = 0; i < ar.size(); ++i)
			// ar[i].setSpeed(level * 50);
	// }
}

void CGAME::resetGame()
{
	cn.setPos(400, 530);
	level = 1;
	for (int i = 0; i < axt.size(); ++i)
		axt[i].setSpeed(100);
	for (int i = 0; i < ac.size(); ++i)
		ac[i].setSpeed(100);
	for (int i = 0; i < axh.size(); ++i)
		axh[i].setSpeed(100);
	for (int i = 0; i < ar.size(); ++i)
		ar[i].setSpeed(100);
	
}

void CGAME::updatePosPeople(Event& event,RenderWindow& window)
{
	cn.update(event, window);
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
bool CGAME::loadGame()
{
	ifstream fin;
	string filename;
	cout << "Input file's name to load ";
	getline(cin, filename);
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Can't open file ";
		return false;
	}
	else
	{
		fin >> level;
		int live;
		fin >> live;
		cn.setLives(live);
		float x, y, speed;
		fin >> x >> y;
		cn.setPos(x, y);
		for (int i = 0;i < axt.size();i++)
		{
			fin >> speed;
			axt[i].setSpeed(speed);
			fin >> x >> y;
			axt[i].setPos(x, y);
		}
		for (int i = 0;i < axh.size();i++)
		{
			fin >> speed;
			axh[i].setSpeed(speed);
			fin >> x >> y;
			axh[i].setPos(x, y);
		}
		for (int i = 0;i < ac.size();i++)
		{
			fin >> speed;
			ac[i].setSpeed(speed);
			fin >> x >> y;
			ac[i].setPos(x, y);
		}
		for (int i = 0;i < ar.size();i++)
		{
			fin >> speed;
			ar[i].setSpeed(speed);
			fin >> x >> y;
			ar[i].setPos(x, y);
		}
		fin.close();
		return true;
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
		fout << level << endl;
		fout << cn.getLivesLeft() << endl;
		fout << cn.getBox().getPosition().x << " " << cn.getBox().getPosition().y << endl;
		for (int i = 0;i < axt.size();i++)
		{
			fout << axt[i].getSpeed() << endl;
			fout << axt[i].getSprite().getPosition().x << " " << axt[i].getSprite().getPosition().y << endl;
		}
		for (int i = 0;i < axh.size();i++)
		{
			fout << axh[i].getSpeed() << endl;
			fout << axh[i].getSprite().getPosition().x << " " << axh[i].getSprite().getPosition().y << endl;
		}
		for (int i = 0;i < ac.size();i++)
		{
			fout << ac[i].getSpeed() << endl;
			fout << ac[i].getSprite().getPosition().x << " " << ac[i].getSprite().getPosition().y << endl;
		}
		for (int i = 0;i < ar.size();i++)
		{
			fout << ar[i].getSpeed() << endl;
			fout << ar[i].getSprite().getPosition().x << " " << ar[i].getSprite().getPosition().y;
			if (i != ar.size() - 1)
				fout << endl;
		}
		fout.close();
	}
}
