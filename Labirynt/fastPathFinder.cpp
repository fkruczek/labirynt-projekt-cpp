#include "pch.h"
#include "fastPathFinder.h"


fastPathFinder::fastPathFinder()
{
}

fastPathFinder::~fastPathFinder()
{
}

int fastPathFinder::findPath()
{
	startR.push(stPntR);
	startC.push(stPntC);

	rq.push_back(startR);
	cq.push_back(startC);

	visited[startR.top()][startC.top()] = true;


	while (!rq.empty()) {
		tempR = rq.front();
		rq.pop_front();
		tempC = cq.front();
		cq.pop_front();

		if (grid[tempR.top()][tempC.top()] == 'K') {
			pathLength = tempR.size();
			reached_end = true;
			break;
		}

		exploreNbrs();

		nodesLeftinLayer--;
		if (nodesLeftinLayer == 0) {
			nodesLeftinLayer = nodesInNextLayer;
			nodesInNextLayer = 0;
			moveCount++;
		}

	}
	if (reached_end) {
		return moveCount;
	}
	return 0;
}

void fastPathFinder::exploreNbrs()
{
	for (int i = 0; i < 4; i++) {
		newR = tempR.top() + directionRow[i];
		newC = tempC.top() + directionCol[i];

		if (newR < 0 || newC < 0) continue;
		if (newR >= gridSize || newC >= gridSize) continue;

		if (visited[newR][newC]) continue;
		if (grid[newR][newC] == '0') continue;

		tempR.push(newR);
		tempC.push(newC);

		if (calculateDistance(newR, newC, exPntR, exPntC) >
			calculateDistance(rq.front().top(), cq.front().top(), exPntR, exPntC)) {
			rq.push_front(tempR);
			cq.push_front(tempC);
		}
		else {
			rq.push_back(tempR);
			cq.push_back(tempC);
		}

		//tylko do reprezentacji graficznej
		visitedFieldsR.push(newR);
		visitedFieldsC.push(newC);

		visited[newR][newC] = true;
		nodesInNextLayer++;
	}

}

void fastPathFinder::setGridSize(int size)
{
	gridSize = size;
}

void fastPathFinder::setGrid(char **givenGrid)
{
	grid = givenGrid;
}

void fastPathFinder::setVisited(bool **givenVisited)
{
	visited = givenVisited;
}

void fastPathFinder::setStartingPoint(int x, int y)
{
	stPntR = x;
	stPntC = y;
}

void fastPathFinder::setExitPoint(int x, int y)
{
	exPntR = x;
	exPntC = y;
}

int fastPathFinder::getPathR()
{
	int wspolzedna;
	while (!tempR.empty()) {
		wspolzedna = tempR.top();
		tempR.pop();
		return wspolzedna;
	}
	return -1;
}

int fastPathFinder::getPathC()
{
	int wspolzedna;
	while (!tempC.empty()) {
		wspolzedna = tempC.top();
		tempC.pop();
		return wspolzedna;
	}
	return -1;
}

int fastPathFinder::getPathLength()
{
	return pathLength;
}

int fastPathFinder::calculateDistance(int x1, int y1, int x2, int y2)
{
	return abs(x1-x2)*abs(y1-y2);
}



