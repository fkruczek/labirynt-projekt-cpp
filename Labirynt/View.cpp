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

void View::drawMaze()
{
	al_init();
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_get_allegro_primitives_version();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = al_create_display(windowSize, windowSize);
	ALLEGRO_COLOR color_wall = al_map_rgb(0, 42, 63);
	ALLEGRO_COLOR color_ground = al_map_rgb(76, 98, 120);
	ALLEGRO_COLOR color_path = al_map_rgb(155, 211, 122);
	ALLEGRO_COLOR color_enter = al_map_rgb(200, 10, 10);
	ALLEGRO_COLOR color_exit = al_map_rgb(100, 100, 10);

	int sizeOfSquare = windowSize / mazeSize;

	for (int row = 0; row < mazeSize; row++) {
		for (int col = 0; col < mazeSize; col++) {
			switch (gridRecipe[col][row]) {
			case 0:
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_wall);
				break;
			case 1:
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_ground);
				break;
			case 2:
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_path);
				break;
			case 3:
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_enter);
				break;
			case 4:
				al_draw_filled_rectangle(row*sizeOfSquare, col*sizeOfSquare, row*sizeOfSquare + sizeOfSquare, col*sizeOfSquare + sizeOfSquare, color_exit);
				break;
			}
		}
	}


	al_flip_display();
	al_rest(6.0f);
	al_destroy_display(display);
	al_shutdown_primitives_addon();
}
