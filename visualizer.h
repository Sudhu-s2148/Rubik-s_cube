#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "raylib.h"
#include "cube.h"

void DrawCubelet(int x, int y, int z, slot_cube* cube);
Color get_raylib_color(enum color c);
void draw_cube(slot_cube* cube);

#endif