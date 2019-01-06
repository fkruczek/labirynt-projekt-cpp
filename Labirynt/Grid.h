#pragma once
#ifndef GRID_H
#define GRID_H

#include <cctype>
#define MIN_MAZE_SIZE 2;
#define MAX_MAZE_SIZE 180;
class Grid
{
private:
	int gridSize;
	char **grid;
public:
	Grid(int size); //random grid
	Grid(std::string fileContent); //grid from file
	~Grid();
	void setSize(std::string fileContent);
	void setSize(int size);
	void allocGrid(int size);
	int randomizeSize();
	bool isValid(std::string fileContent);
	char getField(int x, int y);
	void setField(int x, int y, char fieldType);
	int getSize();
	int getStartingPointX();
	int getStartingPointY();
};
#endif