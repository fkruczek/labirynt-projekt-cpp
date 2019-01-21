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
  Klasa reprezentuj�ca sitak�
*/
class Grid
{
private:
	//! Ilo�� p�l w kolumnie/wierszu
	int gridSize;
	//! Dwuwymiarowa tablica p�l labiryntu
	char **grid;
	//! Dwuwymiarowa tablica p�l labiryntu (pe�ni rol� backupu)
	char **primaryGrid;
	//! Tablica informuj�ca, czy dane pole podczas szukania �cie�ki by�o ju� odwiedzone
	bool **visited;
	std::string fileContentNoWhiteSpaces;

	//! wykorzystywane przy p�tlach w odwiedzamy s�siad�w danego pola
	int rowVect[4] = { -1, 1, 1, -1 };
	int colVect[4] = { 0, 1, -1, -1 };
	int rowDiagVect[4] = { 1, 0, -2, 0 };
	int colDiagVect[4] = { 1, -2, 0, 2 };

public:
	//! Konstruktor domy�lny
	Grid();
	//! Konstuktor do losowanego labiryntu
	/*! Losowo generuje �ciany i pola przechodnie wg szansy kt�r� poda u�ytkownik.
		Je�eli wallPerc == 100, to uruchamia metod� generateMaze().
		Nast�pnie losuje po�o�enie wej�cia i wyj�cia.
	*/
	Grid(int size, int wallPerc);
	//! Konstuktor do labiryntu z pliku
	/*! Konwertuje strumie� z pliku na siatk�.
	*/
	Grid(std::string fileContent);
	//! Usuwa bia�e znaki ze strumienia z pliku
	std::string deleteWhiteSpaces(std::string str);
	~Grid();
	//! Ustawia sk�adow� gridSize na podstawie strumienia z pliku
	void setSize(std::string fileContent);
	void setSize(int size);
	//! Rezerwuje pami�� na siatk� (grid, primaryGrid, validate)
	void allocGrid(int size);
	int randomizeSize();
	//! Rzuca wyj�tkiem, gdy plik jest niepoprawny, lub nie zosta� napisany wg okre�lonych zasad
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

	//! Metoda generuj�ca losowy, zawsze przechodni labirynt
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