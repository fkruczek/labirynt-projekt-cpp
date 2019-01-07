#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "Grid.h"
#include "Field.h"
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
class PathFinder
{
private:
	bool czyZnaleziono = false;
	int mazeSize;
	int pathCounter = 0;
	typedef std::queue<std::stack<Field>> queueOfStacks;
	queueOfStacks paths;
	std::stack<Field> finalPath;
	std::vector<std::stack<Field>> pathVector;

	std::clock_t start;
	double duration;
public:
	PathFinder();
	~PathFinder();
	void setMazeSize(int size);
	bool findPath(Grid & maze);
	void checkNeighbours(Field & field);
	bool isInBorder(Field & field);
	void selectFinalPath(Grid & maze);
	void selectVectorPath(Grid & maze, int n);
	int getPathCounter();
	double getDuration();
};

#endif
