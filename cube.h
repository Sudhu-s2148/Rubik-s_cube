#ifndef CUBE_H
#define CUBE_H

#include "raylib.h"

enum color {
    CUBE_WHITE,
    CUBE_GREEN,
    CUBE_RED,
    CUBE_BLUE,
    CUBE_ORANGE,
    CUBE_YELLOW,
    CUBE_NULL
};
extern const Vector3 corner_position[8];
extern const Vector3 edge_position[12];
extern const Vector3 centre_position[6];

typedef struct {
    enum color colors[3];
    Vector3 cordinate; 
} cubelet;

typedef struct {
    cubelet pieces[26];
} cube;

typedef struct {
    cubelet* piece_slots[20];
} slot_cube;

void init_mutable(cube* mutable, cube* original);
void init_cube(slot_cube* slots, cube* original);

#endif