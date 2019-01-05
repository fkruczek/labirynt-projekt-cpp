#include "pch.h"
#include "allegro5/bitmap_draw.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>

int main(int argc, char **argv) {
/*	int size = 10;
	int windowSize = 400;
	int sizeOfSquare = windowSize / size;
	int gridRecipe[10][10]{ {3,2,1,0,1,1,1,1,0,1},
							   {1,2,2,0,1,0,0,1,0,0},
							   {1,0,2,0,1,1,1,1,0,1},
							   {1,1,2,0,1,0,0,1,0,1},
							   {0,0,2,1,1,1,1,1,1,1},
							   {1,1,2,2,2,2,2,2,0,1},
							   {1,1,1,0,1,0,0,2,0,1},
							   {1,1,0,1,1,1,1,2,0,1},
							   {1,1,1,1,1,1,0,2,2,2},
							   {1,1,1,1,1,0,0,1,0,4} };

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

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
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
	return 0;*/

	FileReader czytnik;
	Grid siatka;
	czytnik.readFromFile();
	//siatka.isValid(czytnik.getFileContent());
	siatka.createGrid(czytnik.getFileContent());
	return 0;
}
