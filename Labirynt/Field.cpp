#include "pch.h"
#include "Field.h"

Field::Field()
{
}

Field::Field(int x, int y, int exPntX, int exPntY)
{
	X = x;
	Y = y;

	distance = abs(x - exPntX)*abs(y - exPntY);
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

int Field::getDistance()
{
	return distance;
}

void Field::setDistance()
{
}
