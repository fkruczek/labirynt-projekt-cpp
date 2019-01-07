#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <queue>
#include <vector>
#include "Field.h"
class PathFinder
{
private:
	int pathCounter = 0;
	typedef std::queue<std::queue<Field>> queueArray;
	queueArray paths;
public:
	bool isPathExists();
	PathFinder();
	~PathFinder();
	void createPath(int size);
	void checkNeighbours(Field & field);
};

#endif
