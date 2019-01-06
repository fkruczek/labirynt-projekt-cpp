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



void View::drawMaze(Grid & Maze)
{
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_init_primitives_addon();

	if (!al_init()) {
		throw "nie udalo sie zainicjalizowac allegro";
	}

	display = al_create_display(windowSize, windowSize);
	if (!display) {
		throw "nie udalo sie utworzyc display";
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_destroy_display(display);
		throw "nie udalo sie utworzyc event_queue";
	}

	al_set_window_title(display, "Labirynt - projekt C++");

	ALLEGRO_COLOR color_wall = al_map_rgb(0, 42, 63);
	ALLEGRO_COLOR color_ground = al_map_rgb(76, 98, 120);
	ALLEGRO_COLOR color_path = al_map_rgb(155, 211, 122);
	ALLEGRO_COLOR color_enter = al_map_rgb(200, 10, 10);
	ALLEGRO_COLOR color_exit = al_map_rgb(100, 100, 10);

	setMazeSize(Maze.getSize());
	int sizeOfSquare = windowSize / mazeSize;

	for (int row = 0; row < mazeSize; row++) {
		for (int col = 0; col < mazeSize; col++) {
			switch (Maze.getField(col,row)) {
			case '0':
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_wall);
				break;
			case '1':
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_ground);
				break;
			case '2':
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_path);
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
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

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
			size = readSize();
		} while (size < 2 || size > 150);

		return size;
	}
}

int View::readSize()
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