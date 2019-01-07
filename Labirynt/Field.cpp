#include "pch.h"
#include "Field.h"

Field::Field()
{
}

Field::Field(int x, int y)
{
	X = x;
	Y = y;
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
