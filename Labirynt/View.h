#pragma once
#ifndef VIEW_H
#define VIEW_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "Grid.h"
#include "PathFinder.h"
#include <ctime>
//!  klasa View
/*!
  Klasa odpowiadajaca za interakcję z użytkownikiem
*/

class View
{
private:
	int mazeSize;
	//! Rozmiar okna z wizualizacją graficzną labiryntu
	int windowSize = 700;
	int wallPerc;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
public:
	View();
	~View();
	void setMazeSize(int gridSize);
	void setWindowSize(int sizeWindow);
	int readNumber();
	//! Prezentacja graficzna oraz interakcja z użytkownikiem (obsługa sterowania użytkownika)
	void drawMaze(Grid & Maze);
	//! Wypisanie menu głównego
	int mainMenu();
	int getWallPerc();
};

#endif
