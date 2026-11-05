#include <stdlib.h>
#include "cube.h"
#include "new_visualiser.h"
#include "moves.h"
int main(){
    cube* canonical = (cube*)malloc(sizeof(cube));
    cube* mutable = (cube*)malloc(sizeof(cube));
    //corners
    canonical->pieces[0] = (cubelet){.colors = {CUBE_RED, CUBE_WHITE, CUBE_GREEN}, .cordinate = corner_position[0]}; 
    canonical->pieces[1] = (cubelet){.colors = {CUBE_ORANGE, CUBE_WHITE ,CUBE_GREEN}, .cordinate = corner_position[1]};
    canonical->pieces[2] = (cubelet){.colors = {CUBE_ORANGE, CUBE_WHITE, CUBE_BLUE}, .cordinate = corner_position[2]};
    canonical->pieces[3] = (cubelet){.colors = {CUBE_RED, CUBE_WHITE, CUBE_BLUE}, .cordinate = corner_position[3]};
    canonical->pieces[4] = (cubelet){.colors = {CUBE_ORANGE, CUBE_YELLOW, CUBE_GREEN}, .cordinate = corner_position[4]};
    canonical->pieces[5] = (cubelet){.colors = {CUBE_RED, CUBE_YELLOW, CUBE_GREEN}, .cordinate = corner_position[5]};
    canonical->pieces[6] = (cubelet){.colors = {CUBE_RED, CUBE_YELLOW, CUBE_BLUE}, .cordinate = corner_position[6]};
    canonical->pieces[7] = (cubelet){.colors = {CUBE_ORANGE, CUBE_YELLOW, CUBE_BLUE}, .cordinate = corner_position[7]};

    //edges
    canonical->pieces[8] = (cubelet){.colors = {CUBE_NULL, CUBE_WHITE, CUBE_GREEN}, .cordinate = edge_position[0]};
    canonical->pieces[9] = (cubelet){.colors = {CUBE_ORANGE, CUBE_WHITE, CUBE_NULL}, .cordinate = edge_position[1]};
    canonical->pieces[10] = (cubelet){.colors ={CUBE_NULL, CUBE_WHITE, CUBE_BLUE, }, .cordinate = edge_position[2]};
    canonical->pieces[11] = (cubelet){.colors ={CUBE_RED, CUBE_WHITE,  CUBE_NULL}, .cordinate = edge_position[3]};
    canonical->pieces[12] = (cubelet){.colors ={CUBE_RED, CUBE_NULL, CUBE_GREEN}, .cordinate = edge_position[4]};
    canonical->pieces[13] = (cubelet){.colors ={CUBE_ORANGE, CUBE_NULL, CUBE_GREEN}, .cordinate = edge_position[5]};
    canonical->pieces[14] = (cubelet){.colors ={CUBE_ORANGE, CUBE_NULL, CUBE_BLUE}, .cordinate = edge_position[6]};
    canonical->pieces[15] = (cubelet){.colors ={CUBE_RED, CUBE_NULL, CUBE_BLUE}, .cordinate = edge_position[7]};
    canonical->pieces[16] = (cubelet){.colors ={CUBE_NULL, CUBE_YELLOW, CUBE_GREEN}, .cordinate = edge_position[8]};
    canonical->pieces[17] = (cubelet){.colors ={CUBE_RED, CUBE_YELLOW,  CUBE_NULL}, .cordinate = edge_position[9]};
    canonical->pieces[18] = (cubelet){.colors ={CUBE_NULL ,CUBE_YELLOW, CUBE_BLUE}, .cordinate = edge_position[10]};
    canonical->pieces[19] = (cubelet){.colors ={CUBE_ORANGE, CUBE_YELLOW, CUBE_NULL}, .cordinate = edge_position[11]};

    //centres

    canonical->pieces[20] = (cubelet){.colors = {CUBE_NULL, CUBE_WHITE, CUBE_NULL}, .cordinate = centre_position[0]};
    canonical->pieces[21] = (cubelet){.colors = {CUBE_NULL, CUBE_NULL,CUBE_GREEN}, .cordinate = centre_position[1]};
    canonical->pieces[22] = (cubelet){.colors = {CUBE_ORANGE, CUBE_NULL, CUBE_NULL}, .cordinate = centre_position[2]};
    canonical->pieces[23] = (cubelet){.colors = {CUBE_NULL, CUBE_NULL, CUBE_BLUE}, .cordinate = centre_position[3]};
    canonical->pieces[24] = (cubelet){.colors = {CUBE_RED, CUBE_NULL, CUBE_NULL}, .cordinate = centre_position[4]};
    canonical->pieces[25] = (cubelet){.colors = {CUBE_NULL, CUBE_YELLOW, CUBE_NULL}, .cordinate = centre_position[5]};   

    init_mutable(mutable,canonical);
    visualise_cube(mutable);

    

    move_U(mutable);
    visualise_cube(mutable);

    move_U(mutable);
    visualise_cube(mutable);

    move_U(mutable);
    visualise_cube(mutable);

    move_U(mutable);
    visualise_cube(mutable);
    return 0;
}