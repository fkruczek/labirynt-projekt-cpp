#pragma once
#ifndef GRID_H
#define GRID_H

#include <cctype>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
#include <time.h>

#define MIN_MAZE_SIZE 2
#define MAX_MAZE_SIZE 150

class Grid
{
private:
	int gridSize;
	char **grid;
	char **primaryGrid;
	bool **visited;
	std::string fileContentNoWhiteSpaces;
public:
	Grid();
	Grid(int size, int wallPerc); //random grid
	Grid(std::string fileContent); //grid from file
	std::string deleteWhiteSpaces(std::string str);
	~Grid();
	void setSize(std::string fileContent);
	void setSize(int size);
	void allocGrid(int size);
	int randomizeSize();
	void validate(std::string fileContent);
	char getField(int x, int y);
	void setField(int x, int y, char fieldType);
	int getSize();
	int getStartingPointX();
	int getStartingPointY();
	int getExitPointX();
	int getExitPointY();

	int countWalkableNbrs(int row, int col);
	bool hasDiagonalNbrs(int row, int col);

	void generateMaze();

	void setVisited(int x, int y, bool state);
	bool isVisited(int x, int y);

	bool isWalkable(int x, int y);
	bool isExitPoint(int x, int y);

	void savePrimaryGrid();
	void readPrimaryGrid();

	int rowVect[4] = { -1, 1, 1, -1 };
	int colVect[4] = { 0, 1, -1, -1 };
	int rowDiagVect[4] = { 1, 0, -2, 0 };
	int colDiagVect[4] = { 1, -2, 0, 2 };


};
#endif