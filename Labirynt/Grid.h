#pragma once

class Grid
{
private:
	int gridSize;
	char **grid;
public:
	Grid();
	~Grid();
	bool isValid(char *stringFromFile);
	void createGrid(char *stringFromFile);
	char getField(int x, int y);
	void setField(int x, int y, char fieldType);
	int getSize();
	int getStartingPointX();
	int getStartingPointY();
};
