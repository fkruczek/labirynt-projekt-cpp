#include "pch.h"
#include "View.h"
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
		}
		catch (const char *error){
			std::cout << "Wystapil blad: " << error << std::endl;
		}
	}
	else {//losowanie labiryntu
		Grid Maze(choice);
		V.drawMaze(Maze);
	}
	return 0;
}
