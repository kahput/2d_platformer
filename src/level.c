#include "level.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <tmx.h>

void* raylib_tex_loader(const char* path) {
	Texture2D* returnValue = malloc(sizeof(Texture2D));
	*returnValue = LoadTexture(path);
	return returnValue;
}

void raylib_free_tex(void* ptr) {
	UnloadTexture(*((Texture2D*)ptr));
	free(ptr);
}
void draw_tile(void* image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
	unsigned int dx, unsigned int dy, float opacity, unsigned int flags) {
	DrawTextureRec(*(Texture2D*)image, (Rectangle){ sx, sy, sw, sh }, (Vector2){ dx, dy }, WHITE);
}

void level_init(Level* level, tmx_map* map) {
	level->map = map;
}

void level_run(Level* level) {
	ClearBackground(WHITE);

	tmx_map* map = level->map;
	tmx_layer* layer = map->ly_head;
	while (layer) {
		if (layer->visible)
			break;

		layer = layer->next;
	}
	unsigned long i, j;
	unsigned int gid, x, y, w, h, flags;
	float op;
	tmx_tileset* ts;
	tmx_image* im;
	void* image;
	op = layer->opacity;
	for (i = 0; i < map->height; i++) {
		for (j = 0; j < map->width; j++) {
			gid = (layer->content.gids[(i * map->width) + j]) & TMX_FLIP_BITS_REMOVAL;
			if (map->tiles[gid] != NULL) {
				ts = map->tiles[gid]->tileset;
				im = map->tiles[gid]->image;
				x = map->tiles[gid]->ul_x;
				y = map->tiles[gid]->ul_y;
				w = ts->tile_width;
				h = ts->tile_height;
				if (im) {
					image = im->resource_image;
				} else {
					image = ts->image->resource_image;
				}
				flags = (layer->content.gids[(i * map->width) + j]) & ~TMX_FLIP_BITS_REMOVAL;
				draw_tile(image, x, y, w, h, j * ts->tile_width, i * ts->tile_height, op, flags); // Function to be implemented
			}
		}
	}
}
