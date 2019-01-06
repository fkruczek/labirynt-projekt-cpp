#include "pch.h"
#include "View.h"

int main(int argc, char **argv) {
	int wybor;
	View Widok;

	wybor = Widok.mainMenu();
	
	if (wybor == 1) {//labirynt z pliku
		try {
			FileReader Czytnik;
			Czytnik.readFromFile();
			Grid Labirynt(Czytnik.getFileContent());
			Widok.drawMaze(Labirynt);
		}
		catch (const char *error){
			std::cout << "Wystapil blad: " << error << std::endl;
		}
	}
	else {//losowanie labiryntu
		Grid Labirynt(wybor);
		Widok.drawMaze(Labirynt);
	}
	return 0;
}
