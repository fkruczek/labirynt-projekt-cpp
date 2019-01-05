#pragma once
#include <cctype>
#define MIN_MAZE_SIZE 2;
#define MAX_MAZE_SIZE 180;
class Grid
{
private:
	int gridSize;
	char **grid;
public:
	Grid();
	~Grid();
	void setSize(std::string fileContent);
	bool isValid(std::string fileContent);
	void createGrid(std::string fileContent);
	char getField(int x, int y);
	void setField(int x, int y, char fieldType);
	int getSize();
	int getStartingPointX();
	int getStartingPointY();
};
