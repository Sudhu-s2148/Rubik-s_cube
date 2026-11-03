#ifndef CUBE_H
#define CUBE_H
enum color {
    CUBE_WHITE,
    CUBE_GREEN,
    CUBE_RED,
    CUBE_BLUE,
    CUBE_ORANGE,
    CUBE_YELLOW
};

//when placed on the top-right edge
typedef struct {
    enum color colors[2];
}edge;

//when placed on the top right corner
typedef struct {
    enum color colors[3];

}corner;

typedef struct{
    corner cornerspieces[8];
    edge edgepieces[12];
}cube;

typedef struct{
    corner* cornerspieces[8];
    edge* edgepieces[12];
}slot_cube;

void init_mutable(cube* mutable, cube* original);
void init_cube(slot_cube* slots, cube* original);

#endif