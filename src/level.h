#pragma once
#include "defines.h"

typedef struct _tmx_map tmx_map;
typedef struct {
	tmx_map* map;
} Level;

void* raylib_tex_loader(const char* path);
void raylib_free_tex(void* ptr);

void level_init(Level* level, tmx_map* map);
void level_run(Level* level);
