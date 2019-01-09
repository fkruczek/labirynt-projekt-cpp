#pragma once
#ifndef VIEW_H
#define VIEW_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "Grid.h"
#include "PathFinder.h"
#include <ctime>

class View
{
private:
	int mazeSize;
	int windowSize = 700;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	int wallPerc;

public:
	View();
	~View();
	void setMazeSize(int gridSize);
	void setWindowSize(int sizeWindow);
	int readNumber();
	void drawMaze(Grid & Maze, PathFinder & Finder);
	int mainMenu();
	int getWallPerc();
};

#endif
