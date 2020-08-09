#ifndef _CGAME_H_
#define _CGAME_H_

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class CGAME
{
private:
	vector<CTRUCK> axt;
	vector<CCAR> axh;
	vector <CBIRD> ac;
	vector <CSNAKE> ar;
	CPEOPLE cn;
	float distance(sf::Vector2f a, sf::Vector2f b);
public:
	CGAME();
	void drawGame();
	~CGAME();
	CPEOPLE getPeople();
	CVEHICLE* getVehicle();
	CANIMAL* getAnimal();
};

#endif // !_CGAME_H_
