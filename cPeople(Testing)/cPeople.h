#ifndef cPeople_h
#define cPeople_h

#define RIGHTMAP 58
#define LEFTMAP 2

#include "cConsole.h"
#include "cPosition.h"
#include <cmath>


class cPeople

{

private:

	cPosition pos;

	bool isDead;

	char** a;  //a[3][5]

	char** emptyPlayer;

	int width = 5, height = 3;

public:

	cPeople(); // set default position

	cPosition getPos();

	cPeople(cPosition pos); // set current position when load game

	~cPeople();

	void Up();

	void Down();

	void Right();

	void Left();

	bool checkIsDead();

	void killPlayer(); // set isDead

	char** shape();

	char** emptyShape();

	//cPosition getPos();

	int getWidth();

	int getHeight();

	//    bool crash(cEnemy);

	int getX();

	int getY();

	void sound();

	// bool crash(cPosition pos, int w, int h);
	// need completed other class

};
#endif // cPeople