#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "cube.h"

const Vector3 corner_position[8] = {
    {1.0f, 1.0f, 1.0f},//0
    {-1.0f, 1.0f, 1.0f},//1
    {-1.0f, 1.0f, -1.0f},//2
    {1.0f, 1.0f, -1.0f},//3
    {-1.0f, -1.0f, 1.0f},//4
    {1.0f, -1.0f, 1.0f},//5
    {1.0f, -1.0f, -1.0f},//6
    {-1.0f, -1.0f, -1.0f}//7
};

const Vector3 edge_position[12] = {
    {0.0f, 1.0f, 1.0f},//0
    {-1.0f, 1.0f, 0.0f},//1
    {0.0f, 1.0f, -1.0f},//2
    {1.0f, 1.0f, 0.0f},//3

    {1.0f, 0.0f, 1.0f},//4
    {-1.0f, 0.0f, 1.0f},//5
    {-1.0f, 0.0f, -1.0f},//6
    {1.0f, 0.0f, -1.0f},//7

    {0.0f, -1.0f, 1.0f},//8
    {1.0f, -1.0f, 0.0f},//9
    {0.0f, -1.0f, -1.0f},//10
    {-1.0f, -1.0f, 0.0f}//11
};

const Vector3 centre_position[6] = {
    {0.0f, 1.0f, 0.0f},//0
    {0.0f, 0.0f, 1.0f},//1
    {-1.0f, 0.0f, 0.0f},//2
    {0.0f, 0.0f, -1.0f},//3
    {1.0f, 0.0f, 0.0f},//4
    {0.0f, -1.0f, 0.0f},//5
};

void init_cube(slot_cube* slots, cube* original) {
    for(int i = 0; i < 20; i++) {
        slots->piece_slots[i] = &original->pieces[i];
    }
}

void init_mutable(cube* mutable, cube* original){
    for(int i = 0; i < 26; i++){
        mutable->pieces[i] = original->pieces[i];
    }
}