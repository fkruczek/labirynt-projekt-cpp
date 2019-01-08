#pragma once
#ifndef VIEW_H
#define VIEW_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "Grid.h"
#include "fastPathFinder.h"

class View
{
private:
	int mazeSize;
	int windowSize = 700;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;



public:
	View();
	~View();
	void setMazeSize(int gridSize);
	void setWindowSize(int sizeWindow);
	int readSize();
	void drawMaze(fastPathFinder & Finder, Grid & Maze);
	int mainMenu();
};

#endif
