#include "pch.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::~Grid()
{
}

void Grid::setSize(std::string fileContent)
{
	if (!fileContent.empty())
		gridSize = fileContent.substr(0, fileContent.find_first_of('\n')).length(); //czyli dlugosc pierwszej linii
	else gridSize = 0;
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

void Grid::createGrid(std::string fileContent)
{
	//ustawienie rozmiaru labiryntu (trzeba bedize to zrobicc gdzies indziej)
	this->setSize(fileContent);
	//alokacja pamieci na labirynt 
	grid = new char*[gridSize];
	for (int i = 0; i < gridSize; ++i)
		grid[i] = new char[gridSize];

	//usuniecie znakow bialych z fileContent
	std::string fileContentN;
	for (size_t i = 0; i < fileContent.size(); i++) {
		if (isalnum(fileContent[i]))
			fileContentN += fileContent[i];
	}

	//utworzenie labiryntu
	for (int row = 0, i = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			grid[row][col] = fileContentN[i++];
		}
	}

	//wyswietlenie labiryntu (TEMPORARY)
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			std::cout << grid[row][col] << " ";
		}
		std::cout << std::endl;
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
			if (grid[row][col] == 'S');
			return row;
		}
	}
}

int Grid::getStartingPointY()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			if (grid[row][col] == 'S');
			return col;
		}
	}
}
