#include "pch.h"
#include "PathFinder.h"


bool PathFinder::isPathExists()
{
	return false;
}

PathFinder::PathFinder()
{
	//std::queue<Field> kolejka;
	Field punkt(1,2);
	paths.push(std::queue<Field>());
	//kolejka fifo
	//kolejka kolejek
}

PathFinder::~PathFinder()
{
}

void PathFinder::createPath(int size)
{
}

void PathFinder::checkNeighbours(Field & field)
{
}
