#include "pch.h"
#include "View.h"
#include "FileReader.h"
#include "PathFinder.h"
#include <ctime>

int main(int argc, char **argv) {
	int choice;
	std::clock_t start; //dorobic ZEGAR!!
	double duration;

	View V;
	choice = V.mainMenu();
	

	if (choice == 1) {//labirynt z pliku
		try {
			FileReader Reader;
			Reader.readFromFile();
			Grid Maze(Reader.getFileContent());
			V.drawMaze(Maze);
			PathFinder Finder;
			Finder.setMazeSize(Maze.getSize());
			if (!Finder.findPath(Maze)) {
				std::cout << "Nie znaleziono sciezki" << std::endl;
			}
			else {
				Finder.selectPath(Maze);
				std::cout << "Znaleziono sciezke" << std::endl;
			}
			V.drawMaze(Maze);
		}
		catch (const char *error){
			std::cout << "Wystapil blad: " << error << std::endl;
		}
	}
	else {//losowanie labiryntu
		try {
			Grid Maze(choice);
			V.drawMaze(Maze);
			PathFinder Finder;
			Finder.setMazeSize(Maze.getSize());
			if (!Finder.findPath(Maze)) {
				std::cout << "Nie znaleziono sciezki" << std::endl;
			}
			else {
				Finder.selectPath(Maze);
				std::cout << "Znaleziono sciezke" << std::endl;
			}
			V.drawMaze(Maze);
		}
		catch (const char *error) {
			std::cout << "Wystapil blad: " << error << std::endl;
		}
	}
	return 0;
}
