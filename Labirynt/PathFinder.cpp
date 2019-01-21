#include "pch.h"
#include "PathFinder.h"



PathFinder::PathFinder()
{
}

PathFinder::~PathFinder()
{
}

bool PathFinder::findPath(Grid & maze)
{
	int exPntX = maze.getExitPointX();
	int exPntY = maze.getExitPointY();

	mazeSize = maze.getSize();
	maze.setVisited(maze.getStartingPointX(), maze.getStartingPointY(), true);
	std::stack<Field> startingPath;
	Field startingPoint(maze.getStartingPointX(), maze.getStartingPointY(), exPntX, exPntY);
	startingPath.push(startingPoint);
	//startingPath->push(startingPoint);
	//paths.push(startingPath);
	paths.push(startingPath);

	start = std::clock();

	while (!paths.empty()) {
		std::stack<Field> tempPath = paths.top();
		//std::stack<Field> tempPath = paths.front();
		paths.pop();
		Field endOfPath = tempPath.top();

		Field nbrN(endOfPath.getX(), endOfPath.getY() - 1, exPntX, exPntY);
		Field nbrS(endOfPath.getX(), endOfPath.getY() + 1, exPntX, exPntY);
		Field nbrW(endOfPath.getX() - 1, endOfPath.getY(), exPntX, exPntY);
		Field nbrE(endOfPath.getX() + 1, endOfPath.getY(), exPntX, exPntY);

		if (isInBorder(nbrN) &&
			maze.isWalkable(nbrN.getX(), nbrN.getY()) &&
			!maze.isVisited(nbrN.getX(), nbrN.getY())) {
			if (maze.isExitPoint(nbrN.getX(), nbrN.getY())) {
				finalPath = tempPath;
				isPathExists = true;

				duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

				return true;
			}
			else {
				std::stack<Field> nextPath = tempPath;
				nextPath.push(nbrN);
				paths.push(nextPath);
				maze.setVisited(nbrN.getX(), nbrN.getY(), true);
			}
		}
		if (isInBorder(nbrS) &&
			maze.isWalkable(nbrS.getX(), nbrS.getY()) &&
			!maze.isVisited(nbrS.getX(), nbrS.getY())) {
			if (maze.isExitPoint(nbrS.getX(), nbrS.getY())) {
				finalPath = tempPath;
				isPathExists = true;

				duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

				return true;
			}
			else {
				std::stack<Field> nextPath = tempPath;
				nextPath.push(nbrS);
				paths.push(nextPath);
				maze.setVisited(nbrS.getX(), nbrS.getY(), true);
			}
		}
		if (isInBorder(nbrE) &&
			maze.isWalkable(nbrE.getX(), nbrE.getY()) &&
			!maze.isVisited(nbrE.getX(), nbrE.getY())) {
			if (maze.isExitPoint(nbrE.getX(), nbrE.getY())) {
				finalPath = tempPath;
				isPathExists = true;

				duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

				return true;
			}
			else {
				std::stack<Field> nextPath = tempPath;
				nextPath.push(nbrE);
				paths.push(nextPath);
				maze.setVisited(nbrE.getX(), nbrE.getY(), true);
			}
		}
		if (isInBorder(nbrW) &&
			maze.isWalkable(nbrW.getX(), nbrW.getY()) &&
			!maze.isVisited(nbrW.getX(), nbrW.getY())) {
			if (maze.isExitPoint(nbrW.getX(), nbrW.getY())) {
				finalPath = tempPath;

				duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

				isPathExists = true;
				return true;
			}
			else {
				std::stack<Field> nextPath = tempPath;
				nextPath.push(nbrW);
				paths.push(nextPath);
				maze.setVisited(nbrW.getX(), nbrW.getY(), true);
			}
		}
		pathVector.push_back(tempPath);
		pathCounter++;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	return false;
}

void PathFinder::setMazeSize(int size)
{
	mazeSize = size;
}


bool PathFinder::isInBorder(Field & field)
{
	if (field.getX() < 0 ||
		field.getY() < 0 ||
		field.getX() >= mazeSize ||
		field.getY() >= mazeSize)
		return false;
	else
		return true;
}

void PathFinder::selectFinalPath(Grid & maze)
{
	if (isPathExists) {
		Field pathField;
		while (finalPath.size() > 1) {
			pathField = finalPath.top();
			finalPath.pop();

			maze.setField(pathField.getX(), pathField.getY(), '3');
		}
	}
}

void PathFinder::selectVectorPath(Grid & maze, int n)
{
	Field pathField;
	while (pathVector.at(n).size() > 1) {
		pathField = pathVector.at(n).top();
		pathVector.at(n).pop();
		maze.setField(pathField.getX(), pathField.getY(), '2');
	}
}

int PathFinder::getPathCounter()
{
	return pathCounter;
}

double PathFinder::getDuration()
{
	return duration;
}


