#ifndef FIELD_H
#define FIELD_H
#include "pch.h"
class Field
{
private:
	int X;
	int Y;
	bool isVisited = false;
	bool isWalkable = false;
public:
	Field();
	Field(int x, int y);
	~Field();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

#endif