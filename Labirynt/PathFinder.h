#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "Grid.h"
#include "Field.h"
#include <queue>
#include <stack>
class PathFinder
{
private:
	int mazeSize;
	int pathCounter = 0;
	typedef std::queue<std::stack<Field>> queueOfStacks;
	queueOfStacks paths;
	std::stack<Field> finalPath;
public:
	PathFinder();
	~PathFinder();
	void setMazeSize(int size);
	bool findPath(Grid & maze);
	void checkNeighbours(Field & field);
	bool isInBorder(Field & field);
	void selectPath(Grid & maze);
};

#endif
