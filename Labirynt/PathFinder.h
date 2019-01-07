#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "pch.h"
#include <queue>
#include <stack>

class PathFinder
{
private:
	int mazeSize;
	int pathCounter = 0;
	typedef std::queue<std::stack<Field>> queueOfStacks;
	queueOfStacks paths;
	Field *path;
public:
	PathFinder();
	~PathFinder();
	void setMazeSize(int size);
	bool findPath(Field & startingPoint, Grid & maze);
	void createPath(int size);
	void checkNeighbours(Field & field);
	bool isInBorder(Field & field);
};

#endif
