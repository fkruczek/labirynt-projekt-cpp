#include "pch.h"
//#include "View.h"
#include "FileReader.h"
//#include "PathFinder.h"
#include "fastPathFinder.h"
#include <ctime>

int main(int argc, char **argv) {
	std::clock_t start;
	double duration;
	try {
		FileReader reader;
		reader.readFromFile();
		Grid maze(100, 20);
		fastPathFinder finder;
		finder.setGrid(maze.getGrid());
		finder.setVisited(maze.getVisited());
		finder.setStartingPoint(maze.getStartingPointX(), maze.getStartingPointY());
		finder.setExitPoint(maze.getExitPointX(), maze.getExitPointY());
		finder.setGridSize(maze.getSize());
		start = std::clock();
		if(finder.findPath())
			std::cout << "znaleziono";
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << "Algorytm znalazl sciezke w " << duration << " sekund\n";
		
		for(int i = 0; i<finder.getPathLength(); i++){
			std::cout << finder.getPathR() << " " << finder.getPathC() << std::endl;
		}
	}
	catch (const char *error) {
		std::cout << "wystapil blad: " << error << std::endl;
	}
	return 0;
}