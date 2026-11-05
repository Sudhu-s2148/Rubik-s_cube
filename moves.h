#ifndef MOVES_H
#define MOVES_H

#include "cube.h"
void rot_anticlk_wise(cube* mutable, int corner_indices[4], int edge_indices[4], int swap[2]);
void move_U(cube* mutable);
void move_R(cube* mutable);


// void orientation_transform(int face,int corner_indices[4],int edge_indices[4]);

// void move_U(slot_cube* slots, int corner_indices[4], int edge_indices[4]);
// void move_Udash(slot_cube* slots);
// void move_2U(slot_cube* slots);

// void move_R(slot_cube* slot_cube);
// void move_D(slot_cube* slots);
// void move_Ddash(slot_cube* slots);
// void move_2D(slot_cube* slots);

// void move_F(slot_cube* slots);
// void move_Fdash(slot_cube* slots);
// void move_2F(slot_cube* slots);
#endif