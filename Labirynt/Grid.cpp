#include "pch.h"
#include "Grid.h"

Grid::Grid()
{
}

Grid::Grid(int size, int wallPerc) //labirynt losowany
{
	srand(time(NULL));
	setSize(size);
	allocGrid(gridSize);
	int randnum1, randnum2, randnum3, randnum4;

	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			randnum1 = rand() % 100;
			if (randnum1<wallPerc) grid[row][col] = '0';
			else grid[row][col] = '1';
		}
	}

	if (wallPerc == 100) generateMaze();

	randnum1 = rand() % gridSize;
	randnum2 = rand() % gridSize;

	setField(randnum1, randnum2, 'S'); //wejscie do labiryntu
	do {
		randnum3 = rand() % gridSize;
		randnum4 = rand() % gridSize;
	} while (randnum3 == randnum1 && randnum4 == randnum2);

	setField(randnum3, randnum4, 'K');  //wyjscie z labiryntu
	savePrimaryGrid();
}

Grid::Grid(std::string fileContent) //labirynt z pliku
{
		setSize(fileContent);

		fileContentNoWhiteSpaces = deleteWhiteSpaces(fileContent);
		validate(fileContent);
		allocGrid(gridSize);

		//string -> grid
		for (int row = 0, i = 0; row < gridSize; row++) {
			for (int col = 0; col < gridSize; col++) {
				grid[col][row] = fileContentNoWhiteSpaces[i++];
			}
		}
		savePrimaryGrid();
}

std::string Grid::deleteWhiteSpaces(std::string str) {
	std::string strNoWhiteSpaces;
	for (size_t i = 0; i < str.size(); i++) {
		if (isalnum(str[i]))
			strNoWhiteSpaces += str[i];
	}
	return strNoWhiteSpaces;
}

Grid::~Grid()
{
	for (int i = 0; i < gridSize; ++i)
		delete[] grid[i];
	delete[] grid;

	for (int i = 0; i < gridSize; ++i)
		delete[] visited[i];
	delete[] visited;
}

void Grid::validate(std::string fileContent)
{
	std::size_t found = fileContent.find_first_not_of("SK01\n");
	if (found != std::string::npos){
		//const char *content = fileContent.c_str();
		throw "Plik zawiera bledne znaki.";
	}
	if (gridSize*gridSize != fileContentNoWhiteSpaces.size()) {
		throw "Niepoprawna liczba znakow";
	}
	if (fileContent.find_first_of('S') != fileContent.find_last_of('S')) {
		throw "Moze byc tylko jedno wejscie";
	}
	if (fileContent.find_first_of('S') == std::string::npos) {
		throw "Brak wejscia";
	}
	if (fileContent.find_first_of('K') == std::string::npos) {
		throw "Brak wyjscia";
	}
}

void Grid::setSize(std::string fileContent)
{
	if (!fileContent.empty())
		gridSize = fileContent.substr(0, fileContent.find_first_of('\n')).length(); //czyli dlugosc pierwszej linii
	else 
		throw "Plik jest pusty";

	if (gridSize < MIN_MAZE_SIZE)
		throw "Plik jest bledny";
	else if (gridSize > MAX_MAZE_SIZE)
		throw "Labirynt jest za duzy";
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

	primaryGrid = new char*[size];
	for (int i = 0; i < size; ++i)
		primaryGrid[i] = new char[size];

	visited = new bool*[size];
	for (int i = 0; i < size; ++i) {
		visited[i] = new bool[size];
		for (int j = 0; j < size; j++) {
			visited[i][j] = false;
		}
	}

}

int Grid::randomizeSize()
{
	gridSize = rand() % MAX_MAZE_SIZE + MIN_MAZE_SIZE;
	return gridSize;
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

int Grid::getExitPointX()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			if (grid[row][col] == 'K')
				return row;
		}
	}
	return 0;
}

int Grid::getExitPointY()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			if (grid[row][col] == 'K')
				return col;
		}
	}
	return 0;
}

void Grid::generateMaze()
{
	std::vector<std::pair<int, int>> fieldVector;
	srand(time(NULL));
	std::pair<int, int> field(0,0), newField;
	int explRow, explCol, randIndex, iterator = 0;

	fieldVector.push_back(field);
	setField(0, 0, '1');
	while (!fieldVector.empty()) {
		if (iterator % 3 == 0) {
			randIndex = rand() % fieldVector.size();
			field = fieldVector.at(randIndex);
			fieldVector.erase(fieldVector.begin() + randIndex);
		}
		else {
			field = fieldVector.back();
			fieldVector.pop_back();
		}
		explRow = field.first;
		explCol = field.second;
		if (countWalkableNbrs(explRow, explCol) > 1) continue;
		setField(explRow, explCol, '1');
		for (int i = 0; i < 4; i++) {
			explRow += rowVect[i];
			explCol += colVect[i];

			if (explRow >= gridSize ||
				explRow < 0 ||
				explCol >= gridSize ||
				explCol < 0 ||
				countWalkableNbrs(explRow, explCol) > 1) {
				continue;
			}

			if (getField(explRow, explCol) == '1') continue;

			newField.first = explRow;
			newField.second = explCol;

			fieldVector.push_back(newField);
		}

		iterator++;
	}
	fieldVector.clear();
}



int Grid::countWalkableNbrs(int row, int col)
{
	int explRow=row, explCol=col, walkableNbrs = 0;

	for (int i = 0; i < 4; i++) {
		explRow += rowVect[i];
		explCol += colVect[i];

		if (explRow >= gridSize ||
			explRow < 0 ||
			explCol >= gridSize ||
			explCol < 0) continue;

		if ('1' == getField(explRow, explCol)) walkableNbrs++;
	}

	return walkableNbrs;
}

bool Grid::hasDiagonalNbrs(int row, int col)
{
	int explRow = row, explCol = col;

	for (int i = 0; i < 4; i++) {
		explRow += rowDiagVect[i];
		explCol += colDiagVect[i];

		if (explRow >= gridSize ||
			explRow < 0 ||
			explCol >= gridSize ||
			explCol < 0) continue;

		if ('0' == getField(explRow, explCol)) return true;
	}
	return false;
}





void Grid::setVisited(int x, int y, bool state)
{
	visited[x][y] = state;
}

bool Grid::isVisited(int x, int y)
{
	return visited[x][y];
}

bool Grid::isWalkable(int x, int y)
{
	if (grid[x][y] == '1' || grid[x][y] == 'K')
		return true;
	else 
		return false;
}

bool Grid::isExitPoint(int x, int y)
{
	if (grid[x][y] == 'K')
		return true;
	else return false;
}

void Grid::savePrimaryGrid()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			primaryGrid[row][col] = grid[row][col];
		}
	}
}

void Grid::readPrimaryGrid()
{
	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			grid[row][col] = primaryGrid[row][col];
			visited[row][col] = false;
		}
	}
}
