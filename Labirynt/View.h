#pragma once
#ifndef VIEW_H
#define VIEW_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "Grid.h"
#include "PathFinder.h"

class View
{
private:
	int mazeSize;
	int windowSize = 700;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	ALLEGRO_COLOR color_wall = al_map_rgb(0, 42, 63);
	ALLEGRO_COLOR color_ground = al_map_rgb(76, 98, 120);
	ALLEGRO_COLOR color_path = al_map_rgb(155, 211, 122);
	ALLEGRO_COLOR color_finalpath = al_map_rgb(255, 170, 122);
	ALLEGRO_COLOR color_enter = al_map_rgb(200, 10, 10);
	ALLEGRO_COLOR color_exit = al_map_rgb(100, 100, 10);

public:
	View();
	~View();
	void setMazeSize(int gridSize);
	void setWindowSize(int sizeWindow);
	int readSize();
	void drawMaze(Grid & Maze);
	int mainMenu();
};

#endif
