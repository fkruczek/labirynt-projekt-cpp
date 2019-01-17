#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "Grid.h"
#include "Field.h"
#include <queue>
#include <stack>
#include <vector>
#include <ctime>

struct CompareDistance {
	bool operator()(std::stack<Field> & p1, std::stack<Field> & p2) {
		return p1.top().getDistance() > p2.top().getDistance();
	}
};

class PathFinder
{
private:
	bool isPathExists = false;
	int mazeSize;
	int pathCounter = 0;
	std::priority_queue<std::stack<Field>, std::vector<std::stack<Field>>, CompareDistance> paths;
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
