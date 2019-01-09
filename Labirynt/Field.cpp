#include "pch.h"
#include "Field.h"

Field::Field()
{
}

Field::Field(int x, int y, int exPntX, int exPntY)
{
	X = x;
	Y = y;
	x = abs(x - exPntX);
	y = abs(y - exPntY);
	distance = sqrt(x*x + y*y);
}


Field::~Field()
{
}

void Field::setX(int x)
{
	X = x;
}

void Field::setY(int y)
{
	Y = y;
}

int Field::getX()
{
	return X;
}

int Field::getY()
{
	return Y;
}

double Field::getDistance()
{
	return distance;
}

void Field::setDistance()
{
}
