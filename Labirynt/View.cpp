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

	setMazeSize(Maze.getSize());
	int sqSize = windowSize / mazeSize;
	windowSize = sqSize * mazeSize;
	display = al_create_display(windowSize, windowSize);
	if (!display) {
		throw "nie udalo sie utworzyc display";
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_destroy_display(display);
		throw "nie udalo sie utworzyc event_queue";
	}

	if (!al_install_mouse()) {
		throw "nie udalo sie zaistalowac myszy";
	}	
	
	if (!al_install_keyboard()) {
		throw "nie udalo sie zainstalowac klawiatury";
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_set_window_title(display, "Labirynt - projekt C++");

	ALLEGRO_COLOR color_wall = al_map_rgb(0, 42, 63);
	ALLEGRO_COLOR color_ground = al_map_rgb(76, 98, 120);
	ALLEGRO_COLOR color_path = al_map_rgb(155, 211, 122);
	ALLEGRO_COLOR color_finalpath = al_map_rgb(255, 130, 102);
	ALLEGRO_COLOR color_enter = al_map_rgb(30, 14, 220);
	ALLEGRO_COLOR color_exit = al_map_rgb(220, 70, 50);

	ALLEGRO_KEYBOARD_STATE keyboard;

	int clickedRow, clickedCol;

	bool done = false;
	bool ready = false;
	bool cont;
	bool fieldSet = false;
	while (!done)
	{
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		cont = done = ready = false;

		Maze.readPrimaryGrid();

		for (int row = 0; row < mazeSize; row++) {
			for (int col = 0; col < mazeSize; col++) {
				switch (Maze.getField(row, col)) {
				case '0':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_wall);
					break;
				case '1':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_ground);
					break;
				case 'S':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_enter);
					break;
				case 'K':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_exit);
					break;
				}
			}
		}
		al_flip_display();
		al_flush_event_queue(event_queue);
		std::cout << "Edytuj labirynt lub nacisnij ENTER zeby rozpoczac szukanie drogi" << std::endl;
		al_register_event_source(event_queue, al_get_mouse_event_source());
		al_init_timeout(&timeout, 0.1);
		al_flush_event_queue(event_queue);
		while (!ready) {
			al_get_keyboard_state(&keyboard);
			bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);
			if (get_event && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				clickedRow = ev.mouse.x / sqSize;
				clickedCol = ev.mouse.y / sqSize;
				switch (Maze.getField(clickedRow, clickedCol)) {
				case '0':
					al_draw_filled_rectangle(clickedRow*sqSize, clickedCol*sqSize, clickedRow*sqSize + sqSize, clickedCol*sqSize + sqSize, color_ground);
					Maze.setField(clickedRow, clickedCol, '1');
					break;
				case '1':
					al_draw_filled_rectangle(clickedRow*sqSize, clickedCol*sqSize, clickedRow*sqSize + sqSize, clickedCol*sqSize + sqSize, color_wall);
					Maze.setField(clickedRow, clickedCol, '0');
					break;
				case 'S':
					std::cout << "Umiesc na mapie punkt startowy!" << std::endl;
					al_draw_filled_rectangle(clickedRow*sqSize, clickedCol*sqSize, clickedRow*sqSize + sqSize, clickedCol*sqSize + sqSize, color_ground);
					Maze.setField(clickedRow, clickedCol, '1');
					al_flip_display();
					while (!fieldSet) {
						al_wait_for_event(event_queue, &ev);
						if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
							clickedRow = ev.mouse.x / sqSize;
							clickedCol = ev.mouse.y / sqSize;
							if (Maze.getField(clickedRow, clickedCol) == 'K') continue;
							Maze.setField(clickedRow, clickedCol, 'S');
							al_draw_filled_rectangle(clickedRow*sqSize, clickedCol*sqSize, clickedRow*sqSize + sqSize, clickedCol*sqSize + sqSize, color_enter);
							fieldSet = true;
						}
					}
					fieldSet = false;
					break;
				case 'K':
					std::cout << "Umiesc na mapie punkt koncowy!" << std::endl;
					al_draw_filled_rectangle(clickedRow*sqSize, clickedCol*sqSize, clickedRow*sqSize + sqSize, clickedCol*sqSize + sqSize, color_ground);
					Maze.setField(clickedRow, clickedCol, '1');
					al_flip_display();
					while (!fieldSet) {
						al_wait_for_event(event_queue, &ev);
						if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
							clickedRow = ev.mouse.x / sqSize;
							clickedCol = ev.mouse.y / sqSize;
							if (Maze.getField(clickedRow, clickedCol) == 'S') continue;
							Maze.setField(clickedRow, clickedCol, 'K');
							al_draw_filled_rectangle(clickedRow*sqSize, clickedCol*sqSize, clickedRow*sqSize + sqSize, clickedCol*sqSize + sqSize, color_exit);
							fieldSet = true;
						}
					}
					fieldSet = false;
					break;
				}
				al_flip_display();
			}
			else if (al_key_down(&keyboard, ALLEGRO_KEY_ENTER)) {
				al_flush_event_queue(event_queue);
				ready = true;
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				done = true;
				break;
			}
		}
		if (done) break;

		al_unregister_event_source(event_queue, al_get_mouse_event_source());
		al_flush_event_queue(event_queue);
		Maze.savePrimaryGrid();

		PathFinder Finder;
		Finder.setMazeSize(Maze.getSize());

		std::cout << "Szukam sciezki..." << std::endl;
		if (!Finder.findPath(Maze)) {
			std::cout << "Nie znaleziono sciezki" << std::endl;
		}
		else {
			std::cout << "Znaleziono sciezke" << std::endl;
		}
		std::cout << "Czas szukania wyniosl " << Finder.getDuration() << "s." << std::endl;
		std::cout << "Nacisnij dowolny klawisz by pominac wizualizacje..."<< std::endl;

		double restTime = 5.0 / (mazeSize*mazeSize);

		al_flush_event_queue(event_queue);
		ALLEGRO_EVENT ev2;

		al_init_timeout(&timeout, restTime);

		done = false;
		for (int nPath = 0; nPath < Finder.getPathCounter() && !done; nPath++) {
					Finder.selectVectorPath(Maze, nPath);
					for (int row = 0; row < mazeSize; row++) {
						for (int col = 0; col < mazeSize; col++) {
							switch (Maze.getField(row, col)) {
							case '0':
								al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_wall);
								break;
							case '1':
								al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_ground);
								break;
							case '2':
								al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_path);
								break;
							case '3':
								al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_finalpath);
								break;
							case 'S':
								al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_enter);
								break;
							case 'K':
								al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_exit);
								break;
							}
						}
					}
					al_flip_display();
					while (true) {
						//al_wait_for_event_timed(event_queue, &ev2, restTime);
						bool get_event = al_wait_for_event_until(event_queue, &ev2, &timeout);
						if (get_event && (ev2.type == 42 || ev2.type == 11))
							done = true;
							break;
					}
				}
		al_flush_event_queue(event_queue);
		Finder.selectFinalPath(Maze);

		for (int row = 0; row < mazeSize; row++) {
			for (int col = 0; col < mazeSize; col++) {
				switch (Maze.getField(row, col)) {
				case '0':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_wall);
					break;
				case '1':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_ground);
					break;
				case '2':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_path);
					break;
				case '3':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_finalpath);
					break;
				case 'S':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_enter);
					break;
				case 'K':
					al_draw_filled_rectangle(row*sqSize, col*sqSize, row*sqSize + sqSize, col*sqSize + sqSize, color_exit);
					break;
				}
			}
		}

		al_flip_display();
		std::cout << "Nacisnij BACKSPACE by edytowac labirynt..." << std::endl;
		al_flush_event_queue(event_queue);
		al_rest(0.5);
		ALLEGRO_EVENT ev3;
		al_get_keyboard_state(&keyboard);
		while (true) {
			bool get_event = al_wait_for_event_until(event_queue, &ev3, &timeout);
			if (get_event && ev3.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				done = true;
				break;
			}
			al_get_keyboard_state(&keyboard);
			if (al_key_down(&keyboard, ALLEGRO_KEY_BACKSPACE)) {
				done = false;
				cont = true;
				break;
			}
		}
		al_flush_event_queue(event_queue);
		if (done) break;
		else if (cont) continue;

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
	std::cout << "Podaj szanse na wystapienie sciany <0 do 99>" << std::endl;
	std::cout << "<100> by wygenerowac labirynt" << std::endl;
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
