#ifndef NEW_VISUALIZER_H
#define NEW_VISUALIZER_H
#include "raylib.h"
#include "cube.h"

Color get_raylib_color(enum color c);
Vector3 get_world_position(cubelet* piece);
Vector3 get_world_position(cubelet* piece);
void draw_sticker_cubelet(cubelet* piece);
void place_stickers(cube** mutable_cube);
void draw_cubelet(cubelet* piece);
void visualise_cube(cube* mutable_cube);

#endif