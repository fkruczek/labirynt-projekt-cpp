#include "pch.h"
#include "View.h"

int main(int argc, char **argv) {

	FileReader czytnik;
	Grid siatka;
	czytnik.readFromFile();
	//siatka.isValid(czytnik.getFileContent());
	siatka.createGrid(czytnik.getFileContent());
	View widok;
	widok.drawMaze();
	return 0;
}
