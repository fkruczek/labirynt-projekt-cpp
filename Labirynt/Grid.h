#pragma once
#ifndef GRID_H
#define GRID_H

#include <cctype>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
#include <time.h>

#define MIN_MAZE_SIZE 2
#define MAX_MAZE_SIZE 150

//!  klasa PathFinder 
/*!
  Klasa reprezentuj¹ca sitakê
*/
class Grid
{
private:
	//! Iloœæ pól w kolumnie/wierszu
	int gridSize;
	//! Dwuwymiarowa tablica pól labiryntu
	char **grid;
	//! Dwuwymiarowa tablica pól labiryntu (pe³ni rolê backupu)
	char **primaryGrid;
	//! Tablica informuj¹ca, czy dane pole podczas szukania œcie¿ki by³o ju¿ odwiedzone
	bool **visited;
	std::string fileContentNoWhiteSpaces;

	//! wykorzystywane przy pêtlach w odwiedzamy s¹siadów danego pola
	int rowVect[4] = { -1, 1, 1, -1 };
	int colVect[4] = { 0, 1, -1, -1 };
	int rowDiagVect[4] = { 1, 0, -2, 0 };
	int colDiagVect[4] = { 1, -2, 0, 2 };

public:
	//! Konstruktor domyœlny
	Grid();
	//! Konstuktor do losowanego labiryntu
	/*! Losowo generuje œciany i pola przechodnie wg szansy któr¹ poda u¿ytkownik.
		Je¿eli wallPerc == 100, to uruchamia metodê generateMaze().
		Nastêpnie losuje po³o¿enie wejœcia i wyjœcia.
	*/
	Grid(int size, int wallPerc);
	//! Konstuktor do labiryntu z pliku
	/*! Konwertuje strumieñ z pliku na siatkê.
	*/
	Grid(std::string fileContent);
	//! Usuwa bia³e znaki ze strumienia z pliku
	std::string deleteWhiteSpaces(std::string str);
	~Grid();
	//! Ustawia sk³adow¹ gridSize na podstawie strumienia z pliku
	void setSize(std::string fileContent);
	void setSize(int size);
	//! Rezerwuje pamiêæ na siatkê (grid, primaryGrid, validate)
	void allocGrid(int size);
	int randomizeSize();
	//! Rzuca wyj¹tkiem, gdy plik jest niepoprawny, lub nie zosta³ napisany wg okreœlonych zasad
	void validate(std::string fileContent);
	//! Zwraca dane pole z siatki
	char getField(int x, int y);
	//! Ustawia dane pole w siatce na podane w argumencie
	void setField(int x, int y, char fieldType);
	int getSize();
	int getStartingPointX();
	int getStartingPointY();
	int getExitPointX();
	int getExitPointY();

	int countWalkableNbrs(int row, int col);
	bool hasDiagonalNbrs(int row, int col);

	//! Metoda generuj¹ca losowy, zawsze przechodni labirynt
	void generateMaze();

	void setVisited(int x, int y, bool state);
	bool isVisited(int x, int y);

	bool isWalkable(int x, int y);
	bool isExitPoint(int x, int y);

	//! Tworzenie "kopii zapasowej" siatki
	void savePrimaryGrid();
	//! Skopiowanie "kopii zapasowej" siatki do tablicy **grid
	void readPrimaryGrid();



};
#endif