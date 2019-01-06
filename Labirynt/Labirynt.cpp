#include "pch.h"
#include "View.h"

int main(int argc, char **argv) {
	int wybor;
	View Widok;
	wybor = Widok.mainMenu();
	
	if (wybor == 1) {//labirynt z pliku

		FileReader Czytnik;
		Czytnik.readFromFile();
		Grid Labirynt(Czytnik.getFileContent());
		Widok.drawMaze(Labirynt);
	}
	else {//losowanie labiryntu
		Grid Labirynt(wybor);
		Widok.drawMaze(Labirynt);
	}
	return 0;
}
