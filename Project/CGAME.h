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
	Sprite m_Heart;
	vector <CTRUCK> axt;
	vector <CCAR> axh;
	vector <CBIRD> ac;
	vector <CSNAKE> ar;
	CTRAFFICLIGHT cd[2];
	CPEOPLE cn;
	float d(sf::Vector2f a, sf::Vector2f b) {
			return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
public:
	CGAME();
	void drawGame(sf::RenderWindow &window);
	void display(RenderWindow& w);
	CPEOPLE getPeople() {	return cn; }
	// CVEHICLE* getVehicle();
	// CANIMAL* getAnimal();
	void changeTrafficLight();
	void resetGame();
	void startGame();
	bool loadGame();
	void saveGame();
	void updatePosPeople(Event& event,RenderWindow& window);
	void updatePosVehicle(float elapsedTime);
	void updatePosAnimal(float elapsedTime);
};

#endif // !_CGAME_H_
