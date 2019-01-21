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
	//PathFinder pathFinder;
	choice = V.mainMenu();
	try {
		if (choice == 1) {//labirynt z plikua
			FileReader Reader;
			Reader.readFromFile();
			Grid Maze(Reader.getFileContent());
			//pathFinder.setMazeSize(Maze.getSize());
			V.drawMaze(Maze);
		}
		else {//losowanie labiryntu
			Grid Maze(choice, V.getWallPerc());
			//pathFinder.setMazeSize(Maze.getSize());
			V.drawMaze(Maze);
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

/*! \mainpage Strona g³ówna dokumentacji

\section intro_sec Informacje
	Projekt z przedmiotu <b>"Programowanie w jêzyku C++"</b> <br>
	Temat:			<b>Labirynt</b> <br>
	Autor:			<b>Fryderyk Kruczek</b> <br>
	Miejscowoœæ:	<b>Rzeszów</b> <br>
	Data:			<b>22.01.2019r.</b> <br>

\section intro_zas Opis dzia³ania
	Program pozwala wygenerowaæ labirynt z pliku ".txt" lub losowy o ustalonej wielkoœci.
	U¿ytkownik mo¿e edytowaæ wygenerowany labirynt i szukaæ w nim œcie¿ki.

\section intro_obsl Instrukcja obs³ugi
\subsection intro_menu Menu w konsoli:
	Naciœnij <b>1</b> by wygenerowaæ labirynt z pliku tekstowego.<br><br>
	Naciœnij <b>2</b> by wygenerowaæ losowy labirynt. <br>
		- W tej opcji nale¿y ustaliæ rozmiar labiryntu oraz szanse na wygenerowanie nieprzechodniej œciany.
	Gdy ustalimy szanse na wygenerowanie na 100 - program <b>wygeneruje losowy labirynt</b>.
\subsection intro_graph Obs³uga interfejsu graficznego:
	Gdy na ekranie uka¿e siê wygenerowany labirynt, u¿ytkownik mo¿e go edytowaæ klikaj¹c na poszczególne pola (w tym wejœcie i wyjœcie).
	W celu rozpoczêcia szukania œcie¿ki nale¿y nacisn¹æ ENTER.
	Po znalezieniu œcie¿ki algorytm rozpocznie wizualizacje szukania drogi w labiryncie.
	Nastêpnie w celu kolejnej mo¿liwoœæi edycji powsta³ego labiryntu nale¿y nacisn¹æ klawisz BACKSPACE
	lub wy³¹czyæ okno z labiryntem w celu utworzenia nowej siatki.
		- Pole ciemne symbolizuje nieprzechodni¹ scianê
		- Pole jasne symbolizuje przechodni¹ sie¿kê.
		- Pole niebieskie symbolizuje wejœcie do labiryntu.
		- Pole czerwone symbolizuje wyjœcie z labiryntu.
	<br>


\subsection intro_txt Plik tekstowy:
	Gdy korzystamy z mo¿liwoœci wygenerowania labiryntu z pliku tekstowego nale¿y go utworzyæ wg zasad:<br>
		- Symbole: Znak S - wejscie do labiryntu, Znak K - wyjœcie z labiryntu, 0 - œciana, 1 - pole przechodnie
		- Siatka musi byæ kwadratowa
		- Rozmiar siatki nie po¿e przekraczaæ 150
		- Mo¿e byæ tylko jedno wejœcie ale wiele wyjœæ
		- Plik musi nazywaæ siê "maze.txt" i znajdowaæ w katalogu glównym programu
Plik musi nazywaæ siê "maze.txt" i znajdowaæ w katalogu glównym programu
\section intro_dodat Dodatkowe informacje
\subsection intro_git Repozytorium GIT
	https://github.com/fkruczek/labirynt-projekt-cpp
\subsection intro_glib U¿yta biblioteka graficzna
	<b>Allegro 5</b>
\subsection intro_rules Zasady przechodzenia labirntu (generowania œcie¿ki).
		- Mo¿na poruszaæ siê tylko w prawo, w lewo, w górê, w dó³ (nie mo¿na przejœæ do pola le¿¹cego na przek¹tnej)
		- Granicê labiryntu traktujemy jako œcianê (wyjœæ mo¿na tylko przez "wyjœcie")

*/