#include <stdio.h>
#include <stdlib.h>
#include "moves.h"
#include "cube.h"
int corners[4];
int edges[4];
void move_U(slot_cube* slot_cube){
    for(int i = 1; i<4; i++){
        corner* temp = slot_cube->cornerspieces[i];
        slot_cube->cornerspieces[i] = slot_cube->cornerspieces[0];
        slot_cube->cornerspieces[0] = temp;   
    }

    for(int i = 1; i<4; i++){
        edge* temp = slot_cube->edgepieces[i];
        slot_cube->edgepieces[i] = slot_cube->edgepieces[0];
        slot_cube->edgepieces[0] = temp;   
    }
}

void move_Udash(slot_cube* slot_cube){
    for(int i = 3; i>0; i--){
        corner* temp = slot_cube->cornerspieces[i];
        slot_cube->cornerspieces[i] = slot_cube->cornerspieces[0];
        slot_cube->cornerspieces[0] = temp;   
    }

    for(int i = 3; i>0; i--){
        edge* temp = slot_cube->edgepieces[i];
        slot_cube->edgepieces[i] = slot_cube->edgepieces[0];
        slot_cube->edgepieces[0] = temp;   
    }
}

void move_2U(slot_cube* slot_cube){
    for(int i = 0; i<2; i++){
        corner* temp = slot_cube->cornerspieces[i+2];
        slot_cube->cornerspieces[i+2] = slot_cube->cornerspieces[i];
        slot_cube->cornerspieces[i] = temp;   
    }

    for(int i = 0; i<2; i++){
        edge* temp = slot_cube->edgepieces[i+2];
        slot_cube->edgepieces[i+2] = slot_cube->edgepieces[i];
        slot_cube->edgepieces[i] = temp;   
    }
}

//down
void move_D(slot_cube* slot_cube){
    for(int i = 4; i<8; i++){
        corner* temp = slot_cube->cornerspieces[i];
        slot_cube->cornerspieces[i] = slot_cube->cornerspieces[4];
        slot_cube->cornerspieces[4] = temp;   
    }

    for(int i = 8; i<12; i++){
        edge* temp = slot_cube->edgepieces[i];
        slot_cube->edgepieces[i] = slot_cube->edgepieces[8];
        slot_cube->edgepieces[8] = temp;   
    }
}

void move_Ddash(slot_cube* slot_cube){
    for(int i = 7; i>4; i--){
        corner* temp = slot_cube->cornerspieces[i];
        slot_cube->cornerspieces[i] = slot_cube->cornerspieces[4];
        slot_cube->cornerspieces[4] = temp;   
    }

    for(int i = 11; i>8; i--){
        edge* temp = slot_cube->edgepieces[i];
        slot_cube->edgepieces[i] = slot_cube->edgepieces[8];
        slot_cube->edgepieces[8] = temp;   
    }
}

void move_2D(slot_cube* slot_cube){
    for(int i = 0; i<2; i++){
        corner* temp = slot_cube->cornerspieces[i+2+4];
        slot_cube->cornerspieces[i+2+4] = slot_cube->cornerspieces[i+4];
        slot_cube->cornerspieces[i+4] = temp;   
    }

    for(int i = 0; i<2; i++){
        edge* temp = slot_cube->edgepieces[i+2+8];
        slot_cube->edgepieces[i+2+8] = slot_cube->edgepieces[i+8];
        slot_cube->edgepieces[i+8] = temp;   
    }
}

void move_F(slot_cube* slot_cube){
    corners[0] = 0;
    corners[1] = 5;
    corners[2] = 4;
    corners[3] = 1;

    edges[0] = 0;
    edges[1] = 4;
    edges[2] = 8;
    edges[3] = 5;
    for(int i = 0; i<4; i++){
        corner* temp = slot_cube->cornerspieces[corners[i]];
        slot_cube->cornerspieces[corners[i]] = slot_cube->cornerspieces[corners[0]];
        slot_cube->cornerspieces[corners[0]] = temp;   
    }

    for(int i = 0; i<4; i++){
        edge* temp = slot_cube->edgepieces[edges[i]];
        slot_cube->edgepieces[edges[i]] = slot_cube->edgepieces[edges[0]];
        slot_cube->edgepieces[edges[0]] = temp;   
    }
}

void move_Fdash(slot_cube* slot_cube){
    corners[0] = 1;
    corners[1] = 4;
    corners[2] = 5;
    corners[3] = 0;

    edges[0] = 5;
    edges[1] = 8;
    edges[2] = 4;
    edges[3] = 0;
    for(int i = 0; i<4; i++){
        corner* temp = slot_cube->cornerspieces[corners[i]];
        slot_cube->cornerspieces[corners[i]] = slot_cube->cornerspieces[corners[0]];
        slot_cube->cornerspieces[corners[0]] = temp;   
    }

    for(int i = 0; i<4; i++){
        edge* temp = slot_cube->edgepieces[edges[i]];
        slot_cube->edgepieces[edges[i]] = slot_cube->edgepieces[edges[0]];
        slot_cube->edgepieces[edges[0]] = temp;   
    }
}

void move_2F(slot_cube* slot_cube){
    corner* temp_corner = slot_cube->cornerspieces[0];
    slot_cube->cornerspieces[0] = slot_cube->cornerspieces[4];
    slot_cube->cornerspieces[4] = temp_corner; 

    temp_corner = slot_cube->cornerspieces[1];
    slot_cube->cornerspieces[1] = slot_cube->cornerspieces[5];
    slot_cube->cornerspieces[5] = temp_corner; 

    edge* temp_edge = slot_cube->edgepieces[0];
    slot_cube->edgepieces[0] = slot_cube->edgepieces[8];
    slot_cube->edgepieces[8] = temp_edge; 

    temp_edge = slot_cube->edgepieces[4];
    slot_cube->edgepieces[4] = slot_cube->edgepieces[5];
    slot_cube->edgepieces[5] = temp_edge; 
}

