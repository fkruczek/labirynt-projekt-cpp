#pragma once
#include "allegro5/bitmap_draw.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
class View
{
private:
	int mazeSize;
	int windowSize = 700;
public:
	View();
	~View();
	void setMazeSize(int gridSize);
	void setWindowSize(int sizeWindow);
	void drawMaze(Grid & Maze);
	int mainMenu();
};

