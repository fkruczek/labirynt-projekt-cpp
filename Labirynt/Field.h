#ifndef FIELD_H
#define FIELD_H

class Field
{
private:
	int X;
	int Y;
	bool isVisited = false;
	bool isWalkable = false;
	int distance;
public:
	Field();
	Field(int x, int y, int exPntX, int exPntY);
	~Field();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getDistance();
	void setDistance();
};

#endif