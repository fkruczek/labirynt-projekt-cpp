#pragma once
#include <queue>
#include <stack>
#include <list>
#include "Grid.h"

class fastPathFinder
{
private:
	int gridSize;
	char **grid;
	bool **visited;
	int stPntR;
	int stPntC;
	int exPntR;
	int exPntC;


	std::queue<std::stack<int>> rq;
	std::queue<std::stack<int>> cq;

	std::stack<int> startR;
	std::stack<int> startC;

	std::stack<int> tempR;
	std::stack<int> tempC;

	//tylko do reprezentacji graficznej
	std::queue<int> visitedFieldsR;
	std::queue<int> visitedFieldsC;
	int pathLength;

	int moveCount = 0;
	int nodesLeftinLayer = 1;
	int nodesInNextLayer = 0;

	bool reached_end = false;

	int directionRow[4] { -1, 1, 0, 0 };
	int directionCol[4] { 0, 0, 1, -1 };

	int newR;
	int newC;



public:
	
	fastPathFinder();
	~fastPathFinder();

	int findPath();
	void exploreNbrs();
	void setGridSize(int size);
	void setGrid(char **givenGrid);
	void setVisited(bool **givenVisited);
	void setStartingPoint(int x, int y);
	void setExitPoint(int x, int y);
	int getPathR();
	int getPathC();
	int getPathLength();
	int getGridSize();
	int calculateDistance(int x1, int y1, int x2, int y2);
};

