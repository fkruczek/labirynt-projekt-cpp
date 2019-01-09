#pragma once
#ifndef GRID_H
#define GRID_H

#include <cctype>
#include <string>
#include <algorithm>


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

	void exportPrimaryGrid();
	void importPrimaryGrid();

	void setVisited(int x, int y, bool state);
	bool isVisited(int x, int y);

	bool isWalkable(int x, int y);
	bool isExitPoint(int x, int y);
};
#endif