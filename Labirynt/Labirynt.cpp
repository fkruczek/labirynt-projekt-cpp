#include "pch.h"
#include "View.h"
#include "FileReader.h"
#include "PathFinder.h"
#include <Windows.h>

void clearScreen(char fill = ' ');

int main(int argc, char **argv) {
	int choice;


	while (true) {
	clearScreen();
	View V;
	PathFinder pathFinder;
	choice = V.mainMenu();
	try {
		if (choice == 1) {//labirynt z plikua
			FileReader Reader;
			Reader.readFromFile();
			Grid Maze(Reader.getFileContent());
			pathFinder.setMazeSize(Maze.getSize());
			V.drawMaze(Maze, pathFinder);
		}
		else {//losowanie labiryntu
			Grid Maze(choice, V.getWallPerc());
			pathFinder.setMazeSize(Maze.getSize());
			V.drawMaze(Maze, pathFinder);
		}
	}
	catch (const char *error) {
		std::cout << "wystapil blad: " << error << std::endl;
	}
	std::cin.get();
	std::cin.get();
	}
	std::cin.get();
	std::cin.get();
	return 0;
}

void clearScreen(char fill) {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}