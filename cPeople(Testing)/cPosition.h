#ifndef cPosition_h
#define cPosition_h



class cPosition {

	int X, Y;

public:

	int getX();

	int getY();



	cPosition() {};

	cPosition(const int x, const int y) {
		X = x;
		Y = y;
	}
	void setPos(int x, int y)
	{
		this->X = x;
		this->Y = y;
	}
	~cPosition() {};

};


#endif // cPosition