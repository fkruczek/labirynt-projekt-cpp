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
			std::cout << "Szukanie sciezki w labiryncie z pliku..." << std::endl;
			FileReader Reader;
			Reader.readFromFile();
			Grid Maze(Reader.getFileContent());
			pathFinder.setMazeSize(Maze.getSize());
			if (!pathFinder.findPath(Maze)) {
				std::cout << "Nie znaleziono sciezki" << std::endl;
			}
			else {
				std::cout << "Znaleziono sciezke" << std::endl;
			}
			V.drawMaze(Maze, pathFinder);
		}
		else {//losowanie labiryntu
			std::cout << "Szukanie sciezki w losowym labiryncie..." << std::endl;
			Grid Maze(choice);
			pathFinder.setMazeSize(Maze.getSize());
			if (!pathFinder.findPath(Maze)) {
				std::cout << "Nie znaleziono sciezki" << std::endl;
			}
			else {
				std::cout << "Znaleziono sciezke" << std::endl;
				std::cout << "Algorytm znalazl sciezke w " << pathFinder.getDuration() << "s." << std::endl;
			}
			V.drawMaze(Maze, pathFinder);
		}
	}
	catch (const char *error) {
		std::cout << "wystapil blad: " << error << std::endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}