#include "defines.h"
#include "level.h"

#include <raylib.h>
#include <tmx.h>

typedef struct {
	Level current_level;
	tmx_map* tmx_maps[TOTAL_LEVELS];
} Game;

void game_init(Game* game);
void game_run(Game* game);
void game_desotry(Game* game);

int main(void) {
	Game game = { 0 };
	game_init(&game);
	game_run(&game);
	game_desotry(&game);
}

void game_init(Game* game) {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Platformer");

	/* Set the callback globs in the main function */
	tmx_img_load_func = raylib_tex_loader;
	tmx_img_free_func = raylib_free_tex;

	game->tmx_maps[0] = tmx_load("assets/data/levels/omni.tmx");
	level_init(&game->current_level, game->tmx_maps[0]);
}

void game_run(Game* game) {
	while (!WindowShouldClose()) {
		BeginDrawing();
		level_run(&game->current_level);

		EndDrawing();
	}
}

void game_desotry(Game* game) {
	CloseWindow();
}
