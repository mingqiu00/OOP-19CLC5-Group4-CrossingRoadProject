#include "CGAME.h"

CGAME::CGAME()
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		cout << "Can't load font";
	}
	m_Heart = Sprite(TextureHolder::GetTexture(
		"graphics/heart.png"));
	level = 1;
	for (int i = 0; i < 5; ++i)
	{
		CCAR car;
		car.spawn();
		axh.push_back(car);
		CBIRD bird;
		bird.spawn();
		ac.push_back(bird);
		CTRUCK truck;
		truck.spawn();
		axt.push_back(truck);
		CSNAKE snake;
		snake.spawn();
		ar.push_back(snake);
	}
	cd[0].setPos(770, 65);	//for car 
	cd[1].setPos(770, 280);	//for truck
}
void CGAME::init()
{
	for (int i = 0;i < 5;i++)
	{
		axh[i].setPos(180 * i, 70);
		ac[i].setPos(180 * i, 180);
		axt[i].setPos(180 * i, 300);
		ar[i].setPos(180 * i, 420);
	}
}
void CGAME::changeTrafficLight()
{
	if (cd[0].getLight())
		cd[0].setRed(770, 65);
	else
		cd[0].setGreen(770, 65);
	if (cd[1].getLight())
		cd[1].setRed(770, 280);
	else
		cd[1].setGreen(770, 280);
}
void CGAME::display(RenderWindow& w)
{
	Level.setFont(font);
	string num = to_string(level);
	string lv = "Level: " + num;
	Level.setFillColor(Color::Black);
	Level.setString(lv);
	Level.setPosition(Vector2f(50, 550));
	w.draw(Level);
	// Lives remaining
	int live = cn.getLivesLeft();
	for (int i = 1;i <= live;i++)
	{
		m_Heart.setPosition(570 + 40 * i, 550);
		w.draw(m_Heart);
	}
}

void CGAME::drawGame(sf::RenderWindow &window)
{
	cn.draw(window);
	display(window);
	for (int i = 0; i < 5; ++i)
	{
		window.draw(axt[i].getSprite());
		window.draw(ac[i].getSprite());
		window.draw(axh[i].getSprite());
		window.draw(ar[i].getSprite());
	}
	window.draw(cd[0].getSprite());
	window.draw(cd[1].getSprite());
}

void CGAME::startGame()
{
	if (level > MAX_LEVEL) return; //cho nay chua xong, neu pha dao thi in ra man hinh thong bao
	if (cn.getPosition().y < 50)
	{
		++level;
		cn.setPos(400, 530);
		for (int i = 0; i < axt.size(); ++i)
			axt[i].setSpeed(level * 50);
		for (int i = 0; i < ac.size(); ++i)
			ac[i].setSpeed(level * 50);
		for (int i = 0; i < axh.size(); ++i)
			axh[i].setSpeed(level * 50);
		for (int i = 0; i < ar.size(); ++i)
			ar[i].setSpeed(level * 50);
	}
}
void CGAME::playagain(RenderWindow& window,Event& event,bool& paused,int& state)
{
	switch (event.type)
	{
	case Event::KeyReleased:
		switch (event.key.code)
		{
		case Keyboard::Num1:
			resetGame();
			window.clear();
			paused = true;
			state = -1;
			break;

		case Keyboard::Num2:
			window.close();
			break;
		}
		break;
	case Event::Closed:
		window.close();

		break;
	}
}
bool CGAME::winGame(RenderWindow& window,int& state)
{
	if (state==3 ||level > MAX_LEVEL)
	{
		state = 3;
		message[0].setFont(font);
		message[0].setFillColor(Color::Blue);
		message[0].setStyle(Text::Bold);
		message[0].setString("YOU WON THE GAME");
		message[0].setPosition(Vector2f(300, 250));
		message[1].setFont(font);
		message[1].setFillColor(Color::Red);
		message[1].setString("Play again?");
		message[1].setPosition(Vector2f(370, 300));
		message[2].setFont(font);
		message[2].setFillColor(Color::Black);
		message[2].setString("1. Yes");
		message[2].setPosition(Vector2f(350, 350));
		message[3].setFont(font);
		message[3].setFillColor(Color::Black);
		message[3].setString("2. No");
		message[3].setPosition(Vector2f(450, 350));
		for (int i = 0;i < 4;i++)
			window.draw(message[i]);
		window.display();
		return true;
	}
	return false;
}
bool CGAME::gameOver(RenderWindow &window,int& state)
{
	if (cn.getLivesLeft() == 0)
	{
		state = 0;
		message[0].setFont(font);
		message[0].setFillColor(Color::Red);
		message[0].setStyle(Text::Bold);
		message[0].setString("GAME OVER");
		message[0].setPosition(Vector2f(330, 200));
		message[1].setFont(font);
		message[1].setFillColor(Color::Red);
		message[1].setString("Play again?");
		message[1].setPosition(Vector2f(345, 300));
		message[2].setFont(font);
		message[2].setFillColor(Color::Black);
		message[2].setString("1. Yes");
		message[2].setPosition(Vector2f(325, 350));
		message[3].setFont(font);
		message[3].setFillColor(Color::Black);
		message[3].setString("2. No");
		message[3].setPosition(Vector2f(425, 350));
		for (int i = 0;i < 4;i++)
			window.draw(message[i]);
		window.display();
		return true;
	}
	return false;
}
void CGAME::resetGame()
{
	cn.setLives(3);
	setPosPeople();
	level = 1;
	for (int i = 0; i < 5; ++i)
	{
		axt[i].setSpeed(100);
		ac[i].setSpeed(100);
		axh[i].setSpeed(100);
		ar[i].setSpeed(100);
	}
	cd[0].setPos(770, 65);	//for car
	cd[1].setPos(770, 280);	//for truck
}

void CGAME::updatePosPeople(Event& event,RenderWindow& window)
{
	cn.update(event, window);
	cn.draw(window);
}

void CGAME::updatePosVehicle(float elapsedTime)
{
	timePassed += elapsedTime;
	for (int i = 0; i < 5; i++)
	{
		axh[i].Move(elapsedTime, cd[0]);
		if (axh[i].checkCollision(cn))
		{
			if (lastHit == 0)
			{
				lastHit = timePassed;
				axh[i].CrashSound();
				cn.loseLife();
			}
			else if (timePassed - lastHit > 3)
			{
				lastHit = timePassed;
				axh[i].CrashSound();
				cn.loseLife();
			}
		}
		axt[i].Move(elapsedTime, cd[1]);
		if (axt[i].checkCollision(cn))
		{
			if (lastHit == 0)
			{
				lastHit = timePassed;
				axt[i].CrashSound();
				cn.loseLife();
			}
			else if (timePassed - lastHit > 3)
			{
				lastHit = timePassed;
				axt[i].CrashSound();
				cn.loseLife();
			}
		}
	}
}

void CGAME::updatePosAnimal(float elapsedTime)
{
	timePassed += elapsedTime;
	for (int i = 0; i < 5; i++)
	{
		ar[i].Move(elapsedTime);
		if (ar[i].checkCollision(cn))
		{
			if (lastHit == 0)
			{
				lastHit = timePassed;
				ar[i].Tell();
				cn.loseLife();
			}
			else if (timePassed - lastHit > 3)
			{
				lastHit = timePassed;
				ar[i].Tell();
				cn.loseLife();
			}
		}
		ac[i].Move(elapsedTime);
		if (ac[i].checkCollision(cn))
		{
			if (lastHit == 0)
			{
				lastHit = timePassed;
				ac[i].Tell();
				cn.loseLife();
			}
			else if (timePassed - lastHit > 3)
			{
				lastHit = timePassed;
				ac[i].Tell();
				cn.loseLife();
			}
		}
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
		fout << cn.getPosition().x << " " << cn.getPosition().y << endl;
		for (int i = 0;i < 5;i++)
		{
			fout << axt[i].getSpeed() << endl;
			fout << axt[i].getSprite().getPosition().x << " " << axt[i].getSprite().getPosition().y << endl;
			fout << axh[i].getSpeed() << endl;
			fout << axh[i].getSprite().getPosition().x << " " << axh[i].getSprite().getPosition().y << endl;
			fout << ac[i].getSpeed() << endl;
			fout << ac[i].getSprite().getPosition().x << " " << ac[i].getSprite().getPosition().y << endl;
			fout << ar[i].getSpeed() << endl;
			fout << ar[i].getSprite().getPosition().x << " " << ar[i].getSprite().getPosition().y;
			if (i != 4)
				fout << endl;
		}
		fout.close();
	}
}
bool CGAME::save(RenderWindow& window, int& state)
{
	if (state == 2 || Keyboard::isKeyPressed(Keyboard::Escape))
	{
		state = 2;
		message[0].setFont(font);
		message[0].setFillColor(Color::Blue);
		message[0].setStyle(Text::Bold);
		message[0].setString("Save game?");
		message[0].setPosition(Vector2f(350, 250));
		message[1].setFont(font);
		message[1].setFillColor(Color::Black);
		message[1].setString("1. Yes");
		message[1].setPosition(Vector2f(300, 300));
		message[2].setFont(font);
		message[2].setFillColor(Color::Black);
		message[2].setString("2. No");
		message[2].setPosition(Vector2f(470, 300));
		for (int i = 0;i < 3;i++)
			window.draw(message[i]);
		window.display();
		return true;
	}
	return false;
}
void CGAME::chooseSave(RenderWindow& window, Event& event, bool& paused, int& state)
{
	switch (event.type)
	{
	case Event::KeyReleased:
		switch (event.key.code)
		{
		case Keyboard::Num1:
			saveGame(window);
			paused = true;
			state = -1;
			break;

		case Keyboard::Num2:
			window.close();
			break;
		}
		break;
	case Event::Closed:
		window.close();

		break;
	}
}
bool CGAME::pause(RenderWindow& window,int& state)
{
	if (state==0 || Keyboard::isKeyPressed(Keyboard::P))
	{
		state = 0;
		message[0].setFont(font);
		message[0].setFillColor(Color::Blue);
		message[0].setStyle(Text::Bold);
		message[0].setString("PAUSED");
		message[0].setPosition(Vector2f(350, 250));
		message[1].setFont(font);
		message[1].setFillColor(Color::Black);
		message[1].setString("1. Reset");
		message[1].setPosition(Vector2f(280, 300));
		message[2].setFont(font);
		message[2].setFillColor(Color::Black);
		message[2].setString("2. Exit");
		message[2].setPosition(Vector2f(450, 300));
		for (int i = 0;i < 3;i++)
			window.draw(message[i]);
		window.display();
		return true;
	}
	return false;
}
