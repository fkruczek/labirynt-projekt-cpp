#include "pch.h"
#include "View.h"



View::View()
{

}


View::~View()
{
}

void View::setMazeSize(int gridSize)
{
	mazeSize = gridSize;
}

void View::setWindowSize(int sizeWindow)
{
	windowSize = sizeWindow;
}



void View::drawMaze(Grid & Maze, PathFinder & Finder)
{
	al_set_new_display_flags(ALLEGRO_WINDOWED);

	al_init_primitives_addon();

	if (!al_init()) {
		throw "nie udalo sie zainicjalizowac allegro";
	}

	setMazeSize(Maze.getSize());
	int sizeOfSquare = windowSize / mazeSize;
	windowSize = sizeOfSquare * mazeSize;
	display = al_create_display(windowSize, windowSize);
	if (!display) {
		throw "nie udalo sie utworzyc display";
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_destroy_display(display);
		throw "nie udalo sie utworzyc event_queue";
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_set_window_title(display, "Labirynt - projekt C++");

	ALLEGRO_COLOR color_wall = al_map_rgb(0, 42, 63);
	ALLEGRO_COLOR color_ground = al_map_rgb(76, 98, 120);
	ALLEGRO_COLOR color_path = al_map_rgb(155, 211, 122);
	ALLEGRO_COLOR color_finalpath = al_map_rgb(255, 130, 102);
	ALLEGRO_COLOR color_enter = al_map_rgb(30, 14, 220);
	ALLEGRO_COLOR color_exit = al_map_rgb(220, 70, 50);

	bool done = false;
	while (!done)
	{
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;


		for (int row = 0; row < mazeSize; row++) {
			for (int col = 0; col < mazeSize; col++) {
				switch (Maze.getField(col, row)) {
				case '0':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_wall);
					break;
				case '1':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_ground);
					break;
				case '2':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_path);
					break;
				case '3':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_finalpath);
					break;
				case 'S':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_enter);
					break;
				case 'K':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_exit);
					break;
				}
			}
		}

		al_flip_display();
		//w tym momencie jezeli enter to dalej, jezeli naklikane to zmieniaj wartosci pol w labiryncie
		//jezeli nacisniete na wyjscie/wejscie to nastepny polozony to bedzie wyjscie/wejscie
		//jezeli enter to szukaj sciezki
		al_rest(1);

		if (!Finder.findPath(Maze)) {
			std::cout << "Nie znaleziono sciezki" << std::endl;
		}
		else {
			std::cout << "Znaleziono sciezke" << std::endl;
		}
		std::cout << "Czas szukania " << Finder.getDuration() << "s." << std::endl;

		double restTime = 1.0 / (mazeSize);
		al_init_timeout(&timeout, restTime);


		for (int nPath = 0; nPath < Finder.getPathCounter(); nPath++) {
			Finder.selectVectorPath(Maze, nPath);
			for (int row = 0; row < mazeSize; row++) {
				for (int col = 0; col < mazeSize; col++) {
					switch (Maze.getField(col, row)) {
					case '0':
						al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_wall);
						break;
					case '1':
						al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_ground);
						break;
					case '2':
						al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_path);
						break;
					case '3':
						al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_finalpath);
						break;
					case 'S':
						al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_enter);
						break;
					case 'K':
						al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_exit);
						break;
					}
				}
			}
			al_flip_display();
			al_rest(restTime);
			bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

			if (get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				done = true;
				break;
			}
		}

		if (done) break;

		Finder.selectFinalPath(Maze);

		for (int row = 0; row < mazeSize; row++) {
			for (int col = 0; col < mazeSize; col++) {
				switch (Maze.getField(col, row)) {
				case '0':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_wall);
					break;
				case '1':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_ground);
					break;
				case '2':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_path);
					break;
				case '3':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_finalpath);
					break;
				case 'S':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_enter);
					break;
				case 'K':
					al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_exit);
					break;
				}
			}
		}
		al_flip_display();
		

		while (true) {
			al_wait_for_event(event_queue, &ev);
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				done = true;
				break;
			}
		}
		if (done) break;

	}
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_shutdown_primitives_addon();

}

int View::mainMenu()
{
	std::cout << "Program LABIRYNT" << std::endl;
	std::cout << "Autor: Fryderyk Kruczek" << std::endl;

	std::cout << "MENU:" << std::endl;
	std::cout << "1. Pobierz labirynt z pliku 'maze.txt' " << std::endl;
	std::cout << "2. Losuj labirynt" << std::endl;
	std::cout << "WYBOR: ";

	char choice;
	do {
		std::cin >> choice;
	} while (choice != '1' && choice != '2');
	if (choice == '1') {
		return 1;
	}
	else {
		std::cout << "Podaj rozmiar labiryntu (od 2 do 150): " << std::endl;

		int size;
		do {
			size = readNumber();
		} while (size < MIN_MAZE_SIZE || size > MAX_MAZE_SIZE);

		return size;
	}
}

int View::getWallPerc()
{
	std::cout << "Podaj szanse na wystapienie sciany w procentach:" << std::endl;
	do {
		wallPerc = readNumber();
	} while (wallPerc < 0 || wallPerc > 100);

	return wallPerc;
}

int View::readNumber()
{
	int size;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
	while (!(std::cin >> size)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	return size;
}
