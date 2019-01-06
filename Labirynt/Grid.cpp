#include "pch.h"
#include "Grid.h"


Grid::Grid(int size) //labirynt losowany
{
	setSize(size);
	allocGrid(gridSize);
	int randnum1, randnum2, randnum3, randnum4;

	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			randnum1 = rand() % 100;
			if (randnum1<35) grid[row][col] = '0';
			else grid[row][col] = '1';
		}
	}

	randnum1 = rand() % gridSize;
	randnum2 = rand() % gridSize;

	grid[randnum1][randnum2] = 'S'; //wejscie do labiryntu
	do {
		randnum3 = rand() % gridSize;
		randnum4 = rand() % gridSize;
	} while (randnum3 == randnum1 && randnum4 == randnum1);

	grid[randnum3][randnum4] = 'K'; //wyjscie z labiryntu


}

Grid::Grid(std::string fileContent) //labirynt z pliku
{
		validate(fileContent);

		setSize(fileContent);

		allocGrid(gridSize);

		//usuniecie znakow bialych z fileContent
		std::string fileContentN;
		for (size_t i = 0; i < fileContent.size(); i++) {
			if (isalnum(fileContent[i]))
				fileContentN += fileContent[i];
		}

		//string -> grid
		for (int row = 0, i = 0; row < gridSize; row++) {
			for (int col = 0; col < gridSize; col++) {
				grid[row][col] = fileContentN[i++];
			}
		}
}

Grid::~Grid()
{
	for (int i = 0; i < gridSize; ++i)
		delete[] grid[i];
	delete[] grid;
}

void Grid::setSize(std::string fileContent)
{
	if (!fileContent.empty())
		gridSize = fileContent.substr(0, fileContent.find_first_of('\n')).length(); //czyli dlugosc pierwszej linii
	else gridSize = 0;
}

void Grid::setSize(int size)
{
	gridSize = size;
}

void Grid::allocGrid(int size)
{
	grid = new char*[size];
	for (int i = 0; i < size; ++i)
		grid[i] = new char[size];
}

int Grid::randomizeSize()
{
	gridSize = rand() % 150 + 2;
	return gridSize;
}


void Grid::validate(std::string fileContent)
{
	if (false)
	{
		//Ÿle
		//bool isCorrect = true;
		//const char *content = fileContent.c_str();
		//int len = fileContent.size();

		//fileContent.erase('\n');
		//sprawdzanie poprawnosci
		//koncepcje:
		//czy labirynt jest wiekszy ni¿ 2X2 i mniejszy ni¿ ?X?
		//czy pierwsza linia ma tyle znaków co jest linii
		//trzeba wzi¹æ pod uwagê nawstawianie na koncu enterów (lub napocz¹tku lub gdziekolwiek)
		//czy jest tylko jedno wejscie i jedno wyjscie
		//czy oprócz wejscia i wyjscia sa tylko sciany i pola przechodnie

		throw "!ERROR! !ERROR! !ERROR!";
	}

}

char Grid::getField(int x, int y)
{
	return grid[x][y];
}

void Grid::setField(int x, int y, char fieldType)
{
	grid[x][y] = fieldType;
}

int Grid::getSize()
{
	return gridSize;
}

int Grid::getStartingPointX()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			if (grid[row][col] == 'S')
				return row;
		}
	}
	return 0;
}

int Grid::getStartingPointY()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			if (grid[row][col] == 'S')
				return col;
		}
	}
	return 0;
}
