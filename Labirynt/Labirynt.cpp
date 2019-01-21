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

/*! \mainpage Strona g��wna dokumentacji

\section intro_sec Informacje
	Projekt z przedmiotu <b>"Programowanie w j�zyku C++"</b> <br>
	Temat:			<b>Labirynt</b> <br>
	Autor:			<b>Fryderyk Kruczek</b> <br>
	Miejscowo��:	<b>Rzesz�w</b> <br>
	Data:			<b>22.01.2019r.</b> <br>

\section intro_zas Opis dzia�ania
	Program pozwala wygenerowa� labirynt z pliku ".txt" lub losowy o ustalonej wielko�ci.
	U�ytkownik mo�e edytowa� wygenerowany labirynt i szuka� w nim �cie�ki.

\section intro_obsl Instrukcja obs�ugi
\subsection intro_menu Menu w konsoli:
	Naci�nij <b>1</b> by wygenerowa� labirynt z pliku tekstowego.<br><br>
	Naci�nij <b>2</b> by wygenerowa� losowy labirynt. <br>
		- W tej opcji nale�y ustali� rozmiar labiryntu oraz szanse na wygenerowanie nieprzechodniej �ciany.
	Gdy ustalimy szanse na wygenerowanie na 100 - program <b>wygeneruje losowy labirynt</b>.
\subsection intro_graph Obs�uga interfejsu graficznego:
	Gdy na ekranie uka�e si� wygenerowany labirynt, u�ytkownik mo�e go edytowa� klikaj�c na poszczeg�lne pola (w tym wej�cie i wyj�cie).
	W celu rozpocz�cia szukania �cie�ki nale�y nacisn�� ENTER.
	Po znalezieniu �cie�ki algorytm rozpocznie wizualizacje szukania drogi w labiryncie.
	Nast�pnie w celu kolejnej mo�liwo��i edycji powsta�ego labiryntu nale�y nacisn�� klawisz BACKSPACE
	lub wy��czy� okno z labiryntem w celu utworzenia nowej siatki.
		- Pole ciemne symbolizuje nieprzechodni� scian�
		- Pole jasne symbolizuje przechodni� sie�k�.
		- Pole niebieskie symbolizuje wej�cie do labiryntu.
		- Pole czerwone symbolizuje wyj�cie z labiryntu.
	<br>


\subsection intro_txt Plik tekstowy:
	Gdy korzystamy z mo�liwo�ci wygenerowania labiryntu z pliku tekstowego nale�y go utworzy� wg zasad:<br>
		- Symbole: Znak S - wejscie do labiryntu, Znak K - wyj�cie z labiryntu, 0 - �ciana, 1 - pole przechodnie
		- Siatka musi by� kwadratowa
		- Rozmiar siatki nie po�e przekracza� 150
		- Mo�e by� tylko jedno wej�cie ale wiele wyj��
		- Plik musi nazywa� si� "maze.txt" i znajdowa� w katalogu gl�wnym programu
Plik musi nazywa� si� "maze.txt" i znajdowa� w katalogu gl�wnym programu
\section intro_dodat Dodatkowe informacje
\subsection intro_git Repozytorium GIT
	https://github.com/fkruczek/labirynt-projekt-cpp
\subsection intro_glib U�yta biblioteka graficzna
	<b>Allegro 5</b>
\subsection intro_rules Zasady przechodzenia labirntu (generowania �cie�ki).
		- Mo�na porusza� si� tylko w prawo, w lewo, w g�r�, w d� (nie mo�na przej�� do pola le��cego na przek�tnej)
		- Granic� labiryntu traktujemy jako �cian� (wyj�� mo�na tylko przez "wyj�cie")

*/