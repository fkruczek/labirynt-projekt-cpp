#include "pch.h"
#include "View.h"

int main(int argc, char **argv) {
	int wybor;
	View widok;
	wybor = widok.mainMenu();
	
	if (wybor == 1) {
		//losowanie labiryntu
		Grid Labirynt;
		widok.drawMaze(Labirynt);
	}
	else {
		//labirynt z pliku
		FileReader Czytnik;
		Czytnik.readFromFile();
		Grid Labirynt(Czytnik.getFileContent());
		widok.drawMaze(Labirynt);
	}
	return 0;
}
