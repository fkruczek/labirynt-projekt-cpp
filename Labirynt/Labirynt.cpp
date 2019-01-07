#include "pch.h"
#include "View.h"
#include "FileReader.h"
#include "PathFinder.h"
#include <ctime>

int main(int argc, char **argv) {
	int choice;

	View V;
	PathFinder pathFinder;
	choice = V.mainMenu();
	
	try {
		if (choice == 1) {//labirynt z pliku
				FileReader Reader;
				Reader.readFromFile();
				Grid Maze(Reader.getFileContent());
				//V.drawMaze(Maze, pathFinder);
				pathFinder.setMazeSize(Maze.getSize());
				if (!pathFinder.findPath(Maze)) {
					std::cout << "Nie znaleziono sciezki" << std::endl;
				}
				else {
					std::cout << "Znaleziono sciezke" << std::endl;
					//pathFinder.selectPath(Maze);
				}
				V.drawMaze(Maze, pathFinder);
		}
		else {//losowanie labiryntu
				Grid Maze(choice);
				//V.drawMaze(Maze, pathFinder);
				pathFinder.setMazeSize(Maze.getSize());
				if (!pathFinder.findPath(Maze)) {
					std::cout << "Nie znaleziono sciezki" << std::endl;
				}
				else {
			//		pathFinder.selectFinalPath(Maze);
					std::cout << "Znaleziono sciezke" << std::endl;
				}
				V.drawMaze(Maze, pathFinder);
			}
	}
	catch (const char *error) {
		std::cout << "wystapil blad: " << error << std::endl;
	}
	return 0;
}
