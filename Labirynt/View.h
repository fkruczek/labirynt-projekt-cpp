#pragma once
#include "allegro5/bitmap_draw.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>
class View
{
private:
	int mazeSize;
	int windowSize = 400;
	int gridRecipe[10][10]{ {3,2,1,0,1,1,1,1,0,1},
							{1,2,2,0,1,0,0,1,0,0},
							{1,0,2,0,1,1,1,1,0,1},
							{1,1,2,0,1,0,0,1,0,1},
							{0,0,2,1,1,1,1,1,1,1},
							{1,1,2,2,2,2,2,2,0,1},
							{1,1,1,0,1,0,0,2,0,1},
							{1,1,0,1,1,1,1,2,0,1},
							{1,1,1,1,1,1,0,2,2,2},
							{1,1,1,1,1,0,0,1,0,4} };
public:
	View(int gridSize);
	~View();
	void setMazeSize(int gridSize);
	void setWindowSize(int sizeWindow);

	//czy napewno grid przekazywac
	void drawMaze(Grid & Maze);
};

