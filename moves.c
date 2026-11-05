#include <stdio.h>
#include <stdlib.h>
#include "moves.h"
#include "cube.h"

int corners[4];
int edges[4];

const char* color_to_string(enum color c) {
    switch (c) {
        case CUBE_WHITE:  return "WHITE";
        case CUBE_GREEN:  return "GREEN";
        case CUBE_RED:    return "RED";
        case CUBE_BLUE:   return "BLUE";
        case CUBE_ORANGE: return "ORANGE";
        case CUBE_YELLOW: return "YELLOW";
        case CUBE_NULL:   return "NULL";
        default:          return "UNKNOWN";
    }
}

void rot_anticlk_wise(cube* mutable, int corner_indices[4], int edge_indices[4], int swap[2]){

    for(int i = 0; i < 4; i++) {
        // Your swap logic
        enum color temp_axis = mutable->pieces[corner_indices[i]].colors[swap[0]];
        mutable->pieces[corner_indices[i]].colors[swap[0]] = mutable->pieces[corner_indices[i]].colors[swap[1]];
        mutable->pieces[corner_indices[i]].colors[swap[1]] = temp_axis;
    }

    for(int i = 0; i<4; i++){
        enum color temp_axis = mutable->pieces[edge_indices[i]].colors[swap[0]];
        mutable->pieces[edge_indices[i]].colors[swap[0]] = mutable->pieces[edge_indices[i]].colors[swap[1]];
        mutable->pieces[edge_indices[i]].colors[swap[1]] = temp_axis;
    }

    Vector3 temp_corner = mutable->pieces[corner_indices[0]].cordinate;
    
    mutable->pieces[corner_indices[0]].cordinate = mutable->pieces[corner_indices[1]].cordinate;
    mutable->pieces[corner_indices[1]].cordinate = mutable->pieces[corner_indices[2]].cordinate;
    mutable->pieces[corner_indices[2]].cordinate = mutable->pieces[corner_indices[3]].cordinate;
    mutable->pieces[corner_indices[3]].cordinate = temp_corner;


    Vector3 temp_edge = mutable->pieces[edge_indices[0]].cordinate;
    mutable->pieces[edge_indices[0]].cordinate = mutable->pieces[edge_indices[1]].cordinate;
    mutable->pieces[edge_indices[1]].cordinate = mutable->pieces[edge_indices[2]].cordinate;
    mutable->pieces[edge_indices[2]].cordinate = mutable->pieces[edge_indices[3]].cordinate;
    mutable->pieces[edge_indices[3]].cordinate = temp_edge;
}

void move_R(cube* mutable){
    int swap[2] = {1,2};
    int corner_indices[4] = {0,3,6,5};
    int edge_indices[4] = {3+8,7+8,9+8,4+8};
    rot_anticlk_wise(mutable, corner_indices, edge_indices, swap);
}

void move_U(cube* mutable){
    int swap[2] = {0,2};
    int corner_indices[4] = {0,1,2,3};
    int edge_indices[4] = {0+8,1+8,2+8,3+8};
    rot_anticlk_wise(mutable, corner_indices, edge_indices, swap);
}


// void orientation_transform(int face,int corner_indices[4],int edge_indices[4]){
//     printf("hello");
//     int* corner_pointer = corner_indices;
//     int* edge_pointer = edge_indices;
//     if(face == CUBE_WHITE){
//         for(int i = 0; i<8;i++){
//             if(corner_position[i][0] == 1){
//                 *(corner_pointer++) = i;
//                 printf("%d",i);
//             }
//         }
//         for(int i = 0; i<12;i++){
//             if(edge_position[i][0] == 1){
//                 *(edge_pointer++) = i;
//                 printf("%d",i);
//             }
//         }
//     }
// }

// void move_U(slot_cube* slot_cube, int corner_indices[4],int edge_indices[4]){
//     for(int i = 1; i<4; i++){
//         printf("/////////////////////////////////");
//         corner* temp = slot_cube->cornerspieces[corner_indices[i]];
//         slot_cube->cornerspieces[corner_indices[i]] = slot_cube->cornerspieces[corner_indices[0]];
//         slot_cube->cornerspieces[corner_indices[0]] = temp;  
//         printf("%d,%d",corner_indices[i],corner_indices[0]);
//         printf("/////////////////////////////////");
//     }

//     for(int i = 1; i<4; i++){
//         edge* temp = slot_cube->edgepieces[edge_indices[i]];
//         slot_cube->edgepieces[edge_indices[i]] = slot_cube->edgepieces[edge_indices[0]];
//         slot_cube->edgepieces[edge_indices[0]] = temp;   
//     }
// }

// void move_Udash(slot_cube* slot_cube){
//     for(int i = 3; i>0; i--){
//         corner* temp = slot_cube->cornerspieces[i];
//         slot_cube->cornerspieces[i] = slot_cube->cornerspieces[0];
//         slot_cube->cornerspieces[0] = temp;   
//     }

//     for(int i = 3; i>0; i--){
//         edge* temp = slot_cube->edgepieces[i];
//         slot_cube->edgepieces[i] = slot_cube->edgepieces[0];
//         slot_cube->edgepieces[0] = temp;   
//     }
// }

// void move_2U(slot_cube* slot_cube){
//     for(int i = 0; i<2; i++){
//         corner* temp = slot_cube->cornerspieces[i+2];
//         slot_cube->cornerspieces[i+2] = slot_cube->cornerspieces[i];
//         slot_cube->cornerspieces[i] = temp;   
//     }

//     for(int i = 0; i<2; i++){
//         edge* temp = slot_cube->edgepieces[i+2];
//         slot_cube->edgepieces[i+2] = slot_cube->edgepieces[i];
//         slot_cube->edgepieces[i] = temp;   
//     }
// }

// //down
// void move_R(slot_cube* slot_cube){
//     int corner_indices[4];
//     int edge_indices[4];
//     orientation_transform(CUBE_WHITE, corner_indices, edge_indices);
//     move_U(slot_cube, corner_indices, edge_indices);
// }

// void move_D_with_U
// (slot_cube* slot_cube){
//     for(int i = 4; i<8; i++){
//         corner* temp = slot_cube->cornerspieces[i];
//         slot_cube->cornerspieces[i] = slot_cube->cornerspieces[4];
//         slot_cube->cornerspieces[4] = temp;   
//     }

//     for(int i = 8; i<12; i++){
//         edge* temp = slot_cube->edgepieces[i];
//         slot_cube->edgepieces[i] = slot_cube->edgepieces[8];
//         slot_cube->edgepieces[8] = temp;   
//     }
// }

// void move_D(slot_cube* slot_cube){
//     for(int i = 4; i<8; i++){
//         corner* temp = slot_cube->cornerspieces[i];
//         slot_cube->cornerspieces[i] = slot_cube->cornerspieces[4];
//         slot_cube->cornerspieces[4] = temp;   
//     }

//     for(int i = 8; i<12; i++){
//         edge* temp = slot_cube->edgepieces[i];
//         slot_cube->edgepieces[i] = slot_cube->edgepieces[8];
//         slot_cube->edgepieces[8] = temp;   
//     }
// }

// void move_Ddash(slot_cube* slot_cube){
//     for(int i = 7; i>4; i--){
//         corner* temp = slot_cube->cornerspieces[i];
//         slot_cube->cornerspieces[i] = slot_cube->cornerspieces[4];
//         slot_cube->cornerspieces[4] = temp;   
//     }

//     for(int i = 11; i>8; i--){
//         edge* temp = slot_cube->edgepieces[i];
//         slot_cube->edgepieces[i] = slot_cube->edgepieces[8];
//         slot_cube->edgepieces[8] = temp;   
//     }
// }

// void move_2D(slot_cube* slot_cube){
//     for(int i = 0; i<2; i++){
//         corner* temp = slot_cube->cornerspieces[i+2+4];
//         slot_cube->cornerspieces[i+2+4] = slot_cube->cornerspieces[i+4];
//         slot_cube->cornerspieces[i+4] = temp;   
//     }

//     for(int i = 0; i<2; i++){
//         edge* temp = slot_cube->edgepieces[i+2+8];
//         slot_cube->edgepieces[i+2+8] = slot_cube->edgepieces[i+8];
//         slot_cube->edgepieces[i+8] = temp;   
//     }
// }

// void move_F(slot_cube* slot_cube){
//     corners[0] = 0;
//     corners[1] = 5;
//     corners[2] = 4;
//     corners[3] = 1;

//     edges[0] = 0;
//     edges[1] = 4;
//     edges[2] = 8;
//     edges[3] = 5;
//     for(int i = 0; i<4; i++){
//         corner* temp = slot_cube->cornerspieces[corners[i]];
//         slot_cube->cornerspieces[corners[i]] = slot_cube->cornerspieces[corners[0]];
//         slot_cube->cornerspieces[corners[0]] = temp;   
//     }

//     for(int i = 0; i<4; i++){
//         edge* temp = slot_cube->edgepieces[edges[i]];
//         slot_cube->edgepieces[edges[i]] = slot_cube->edgepieces[edges[0]];
//         slot_cube->edgepieces[edges[0]] = temp;   
//     }
// }

// void move_Fdash(slot_cube* slot_cube){
//     corners[0] = 1;
//     corners[1] = 4;
//     corners[2] = 5;
//     corners[3] = 0;

//     edges[0] = 5;
//     edges[1] = 8;
//     edges[2] = 4;
//     edges[3] = 0;
//     for(int i = 0; i<4; i++){
//         corner* temp = slot_cube->cornerspieces[corners[i]];
//         slot_cube->cornerspieces[corners[i]] = slot_cube->cornerspieces[corners[0]];
//         slot_cube->cornerspieces[corners[0]] = temp;   
//     }

//     for(int i = 0; i<4; i++){
//         edge* temp = slot_cube->edgepieces[edges[i]];
//         slot_cube->edgepieces[edges[i]] = slot_cube->edgepieces[edges[0]];
//         slot_cube->edgepieces[edges[0]] = temp;   
//     }
// }

// void move_2F(slot_cube* slot_cube){
//     corner* temp_corner = slot_cube->cornerspieces[0];
//     slot_cube->cornerspieces[0] = slot_cube->cornerspieces[4];
//     slot_cube->cornerspieces[4] = temp_corner; 

//     temp_corner = slot_cube->cornerspieces[1];
//     slot_cube->cornerspieces[1] = slot_cube->cornerspieces[5];
//     slot_cube->cornerspieces[5] = temp_corner; 

//     edge* temp_edge = slot_cube->edgepieces[0];
//     slot_cube->edgepieces[0] = slot_cube->edgepieces[8];
//     slot_cube->edgepieces[8] = temp_edge; 

//     temp_edge = slot_cube->edgepieces[4];
//     slot_cube->edgepieces[4] = slot_cube->edgepieces[5];
//     slot_cube->edgepieces[5] = temp_edge; 
// }

