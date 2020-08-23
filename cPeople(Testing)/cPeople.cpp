#include "cPeople.h"

cPeople::cPeople() : isDead(false) { // creating people using ascii
	pos.setPos(34, 28);
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[5];
	}
	//Row1
	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 5; i++) {
		if (i == 0)	a[1][i] = '/';
		if (i == 1)	a[1][i] = '(';
		if (i == 2)	a[1][i] = '_';
		if (i == 3)	a[1][i] = ')';
		if (i == 4)	a[1][i] = '\\';
	}
	//Row3
	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}
}

cPeople::cPeople(cPosition pos) : isDead(false), pos(pos) { // when we move, I rewrite people to pos
	//pos.setPos(pos.getX(), pos.getY());
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[5];
	}
	//Row1
	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 5; i++) {
		if (i == 0)	a[1][i] = '/';
		if (i == 1)	a[1][i] = '(';
		if (i == 2)	a[1][i] = '_';
		if (i == 3)	a[1][i] = ')';
		if (i == 4)	a[1][i] = '\\';
	}
	//Row3
	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}
}

cPeople::~cPeople() // delete People
{
	for (int i = 0; i < 3; i++) {
		delete[] a[i];
		delete[] emptyPlayer[i];
	}
	delete[] a;
	delete[] emptyPlayer;
}

void cPeople::killPlayer() {
	isDead = true;
}

char** cPeople::shape() { // draw people
	return a;
}

char** cPeople::emptyShape() {
	return emptyPlayer;
}

cPosition cPeople::getPos() {
	return pos;
}

int cPeople::getX() {
	return pos.getX();
}

int cPeople::getY() {
	return pos.getY();
}

int cPeople::getHeight() {
	return height;
}

int cPeople::getWidth() {
	return width;
}

void cPeople::Up() {
	sound();
	if (pos.getX() <= 3) return;
	pos.setPos(pos.getX() - 3, pos.getY());
}

void cPeople::Down() {
	sound();
	if (pos.getX() + 3 > 34) return;
	pos.setPos(pos.getX() + 3, pos.getY());
}

void cPeople::Left() {
	sound();
	if (pos.getY() <= LEFTMAP) return;
	pos.setPos(pos.getX(), pos.getY() - 1);
}

void cPeople::Right() {
	sound();
	if (pos.getY() + 2 >= RIGHTMAP) return;
	pos.setPos(pos.getX(), pos.getY() + 1);
}

bool cPeople::checkIsDead() {
	return isDead;
}