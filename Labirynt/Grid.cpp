#include "pch.h"
#include "Grid.h"


Grid::Grid(int size) //labirynt losowany
{
	setSize(size);
	allocGrid(gridSize);
	int randnum1, randnum2, randnum3, randnum4;

	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			randnum1 = rand() % 2;
			if (randnum1) grid[row][col] = '0';
			else grid[row][col] = '1';
		}
	}

	randnum1 = rand() % gridSize;
	randnum2 = rand() % gridSize;

	grid[randnum1][randnum2] = 'S';
	do {
		randnum3 = rand() % gridSize;
		randnum4 = rand() % gridSize;
	} while (randnum3 != randnum1 || randnum4 != randnum1);

	grid[randnum3][randnum4] = 'K';


}

Grid::Grid(std::string fileContent) //labirynt z pliku
{
	//ustawienie rozmiaru labiryntu (trzeba bedize to zrobicc gdzies indziej)
	this->setSize(fileContent);

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



bool Grid::isValid(std::string fileContent)
{
	//Ÿle
	bool isCorrect = true;
	const char *content = fileContent.c_str();
	int len = fileContent.size();
	int lineSize = 0;
	int newLineCount = 1;

	for (int i = 0; content[i] != '\n'; i++) {
		lineSize++;
	}

	for (int i = 0; i < len; i++) {
		if (content[i] == '\n') newLineCount++;
	}

	//fileContent.erase('\n');

	std::cout << fileContent;
	//sprawdzanie poprawnosci
	//koncepcje:
	//czy labirynt jest wiekszy ni¿ 2X2 i mniejszy ni¿ ?X?
	//czy pierwsza linia ma tyle znaków co jest linii
	//trzeba wzi¹æ pod uwagê nawstawianie na koncu enterów (lub napocz¹tku lub gdziekolwiek)
	//czy jest tylko jedno wejscie i jedno wyjscie
	//czy oprócz wejscia i wyjscia sa tylko sciany i pola przechodnie
	return isCorrect;
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
