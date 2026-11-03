#include <stdlib.h>
#include "cube.h"
#include "visualizer.h"
#include "moves.h"
int main(){
    cube* canonical = (cube*)malloc(sizeof(cube));
    cube* mutable = (cube*)malloc(sizeof(cube));

    canonical->cornerspieces[0] = (corner){{CUBE_WHITE, CUBE_RED, CUBE_GREEN}};
    canonical->cornerspieces[1] = (corner){{CUBE_WHITE, CUBE_GREEN, CUBE_ORANGE}};
    canonical->cornerspieces[2] = (corner){{CUBE_WHITE, CUBE_ORANGE, CUBE_BLUE}};
    canonical->cornerspieces[3] = (corner){{CUBE_WHITE, CUBE_BLUE, CUBE_RED}};
    canonical->cornerspieces[4] = (corner){{CUBE_YELLOW, CUBE_ORANGE, CUBE_GREEN}};
    canonical->cornerspieces[5] = (corner){{CUBE_YELLOW, CUBE_GREEN, CUBE_RED}};
    canonical->cornerspieces[6] = (corner){{CUBE_YELLOW, CUBE_RED, CUBE_BLUE}};
    canonical->cornerspieces[7] = (corner){{CUBE_YELLOW, CUBE_BLUE, CUBE_ORANGE}};

    canonical->edgepieces[0] = (edge){{CUBE_WHITE, CUBE_GREEN}};
    canonical->edgepieces[1] = (edge){{CUBE_WHITE, CUBE_ORANGE}};
    canonical->edgepieces[2] = (edge){{CUBE_WHITE, CUBE_BLUE}};
    canonical->edgepieces[3] = (edge){{CUBE_WHITE, CUBE_RED}};
    canonical->edgepieces[4] = (edge){{CUBE_RED, CUBE_GREEN}};
    canonical->edgepieces[5] = (edge){{CUBE_GREEN, CUBE_ORANGE}};
    canonical->edgepieces[6] = (edge){{CUBE_ORANGE, CUBE_BLUE}};
    canonical->edgepieces[7] = (edge){{CUBE_BLUE, CUBE_RED}};
    canonical->edgepieces[8] = (edge){{CUBE_YELLOW, CUBE_GREEN}};
    canonical->edgepieces[9] = (edge){{CUBE_YELLOW, CUBE_RED}};
    canonical->edgepieces[10] = (edge){{CUBE_YELLOW, CUBE_BLUE}};
    canonical->edgepieces[11] = (edge){{CUBE_YELLOW, CUBE_ORANGE}};

    init_mutable(mutable,canonical);
    slot_cube* slot_cube = malloc(sizeof *slot_cube);
    init_cube(slot_cube, mutable);

    move_F(slot_cube);
    draw_cube(slot_cube);

    move_Fdash(slot_cube);
    draw_cube(slot_cube);

    move_2F(slot_cube);
    draw_cube(slot_cube);
    return 1;
}