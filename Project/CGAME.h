#ifndef _CGAME_H_
#define _CGAME_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include <SFML/Graphics.hpp>
#include "CPEOPLE.h"
using namespace std;
#define MAX_LEVEL 5

class CGAME
{
private:
	int level = 0;
	Font font;
	Text Level;
	Text message[3];
	Sprite m_Heart;
	vector <CTRUCK> axt;
	vector <CCAR> axh;
	vector <CBIRD> ac;
	vector <CSNAKE> ar;
	CTRAFFICLIGHT cd[2];
	CPEOPLE cn;
	double lastHit = 0;
	double timePassed=0;
	float d(sf::Vector2f a, sf::Vector2f b) {
			return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
public:
	CGAME();
	void init();
	void drawGame(sf::RenderWindow &window);
	void display(RenderWindow& w);
	CPEOPLE getPeople() {	return cn; }
	void changeTrafficLight();
	bool gameOver(RenderWindow& window,Event& event,int& state);
	void resetGame();
	void startGame();
	bool loadGame();
	void saveGame();
	void updatePosPeople(Event& event,RenderWindow& window);
	void updatePosVehicle(float elapsedTime);
	void updatePosAnimal(float elapsedTime);
	void setPosPeople() {
		cn.setPosition(sf::Vector2f(375, 550));

	}
};

#endif // !_CGAME_H_
