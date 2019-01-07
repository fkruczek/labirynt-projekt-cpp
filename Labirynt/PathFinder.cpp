#include "PathFinder.h"

bool PathFinder::findPath(Field & startingPoint, Grid & maze)
{
	mazeSize = maze.getSize();
	maze.setVisited(startingPoint.getX, startingPoint.getY, true);
	paths.push.push(startingPoint);
	while (!paths.empty()) {
		std::stack<Field> tempPath = paths.front();
		Field endOfPath = tempPath.top();

		Field nbrN(endOfPath.getX, endOfPath.getY - 1);
		Field nbrS(endOfPath.getX, endOfPath.getY + 1);
		Field nbrW(endOfPath.getX - 1, endOfPath.getY);
		Field nbrE(endOfPath.getX + 1, endOfPath.getY);

		if (isInBorder(nbrN) && maze.isWalkable(nbrN.getX, nbrN.getX)){

		}

		

	}
	return false;
}

PathFinder::PathFinder()
{
}

PathFinder::~PathFinder()
{
}

void PathFinder::setMazeSize(int size)
{
	mazeSize = size;
}

void PathFinder::createPath(int size)
{
}

void PathFinder::checkNeighbours(Field & field)
{
}

bool PathFinder::isInBorder(Field & field)
{
	if (field.getX < 0 ||
		field.getY < 0 ||
		field.getX > mazeSize ||
		field.getY > mazeSize)
		return false;
	else
		return true;
}

