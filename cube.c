#include <stdio.h>
#include <stdlib.h>
#include "cube.h"

void init_cube(slot_cube* slots, cube* original) {
    for(int i = 0; i < 8; i++) {
        slots->cornerspieces[i] = &original->cornerspieces[i];
    }

    for(int i = 0; i < 12; i++) {
        slots->edgepieces[i] = &original->edgepieces[i];
    }
}

void init_mutable(cube*mutable, cube* original){
    for(int i = 0; i<8; i++){
        mutable->cornerspieces[i] = original->cornerspieces[i];
    }

    for(int i = 0; i<12; i++){
        mutable->edgepieces[i] = original->edgepieces[i];
    }
}
