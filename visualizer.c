#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>

#define CUBELET_SIZE 0.9f
#define STICKER_SIZE 0.76f
#define SPACING 1.0f
#define OFFSET 0.46f

Color get_raylib_color(enum color c)
{
    switch (c)
    {
        case CUBE_WHITE:  return WHITE;
        case CUBE_GREEN:  return GREEN;
        case CUBE_RED:    return RED;
        case CUBE_BLUE:   return BLUE;
        case CUBE_ORANGE: return ORANGE;
        case CUBE_YELLOW: return YELLOW;

        default: return BLACK;
    }
}

void DrawCubelet(int x, int y, int z, slot_cube* cube)
{
    Vector3 position = {
        x * SPACING,
        y * SPACING,
        z * SPACING
    };

    // Dark cubelet body
    DrawCubeV(
        position,
        (Vector3){CUBELET_SIZE, CUBELET_SIZE, CUBELET_SIZE},
        DARKGRAY
    );

    //corners
    if (abs(x)+abs(y)+abs(z) == 3){
        //UFR
        if(x == 1 && y == 1 && z == 1){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[0]->colors[0]));

            DrawCubeV((Vector3){position.x + OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[0]->colors[1]));

            DrawCubeV((Vector3){position.x, position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[0]->colors[2]));
        }
        //UBR
        else if(x == 1 && y == 1 && z == -1){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[3]->colors[0]));

            DrawCubeV((Vector3){position.x + OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[3]->colors[2]));

            DrawCubeV((Vector3){position.x, position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[3]->colors[1]));
        }

        //DFR
        else if(x == 1 && y == -1 && z == 1){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[5]->colors[0]));

            DrawCubeV((Vector3){position.x + OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[5]->colors[2]));

            DrawCubeV((Vector3){position.x, position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[5]->colors[1]));
        }

        //DBR
        else if(x == 1 && y == -1 && z == -1){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[6]->colors[0]));

            DrawCubeV((Vector3){position.x + OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[6]->colors[1]));

            DrawCubeV((Vector3){position.x, position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[6]->colors[2]));
        }

        //TFL
        else if(x == -1 && y == 1 && z == 1){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[1]->colors[0]));

            DrawCubeV((Vector3){position.x - OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[1]->colors[2]));

            DrawCubeV((Vector3){position.x, position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[1]->colors[1]));
        }

        //TBL
        else if(x == -1 && y == 1 && z == -1){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[2]->colors[0]));

            DrawCubeV((Vector3){position.x - OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[2]->colors[1]));

            DrawCubeV((Vector3){position.x, position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[2]->colors[2]));
        }

        //DFL
        else if(x == -1 && y == -1 && z == 1){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[4]->colors[0]));

            DrawCubeV((Vector3){position.x - OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[4]->colors[1]));

            DrawCubeV((Vector3){position.x, position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[4]->colors[2]));
        }
        else if(x == -1 && y == -1 && z == -1){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[7]->colors[0]));

            DrawCubeV((Vector3){position.x - OFFSET, position.y, position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->cornerspieces[7]->colors[2]));

            DrawCubeV((Vector3){position.x, position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->cornerspieces[7]->colors[1]));
        }
    }

    //edges
    else if (abs(x)+abs(y)+abs(z) == 2){
        if(x == 0 && y == 1 && z == 1){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[0]->colors[0]));

            DrawCubeV((Vector3){position.x , position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[0]->colors[1]));
        }
        else if(x == 0 && y == 1 && z == -1){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[2]->colors[0]));

            DrawCubeV((Vector3){position.x , position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[2]->colors[1]));
        }
        else if(x == 0 && y == -1 && z == 1){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[8]->colors[0]));

            DrawCubeV((Vector3){position.x , position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[8]->colors[1]));
        }
        else if(x == 0 && y == -1 && z == -1){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[10]->colors[0]));

            DrawCubeV((Vector3){position.x , position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[10]->colors[1]));
        }



        else if(x == 1 && y == 0 && z == 1){
            DrawCubeV((Vector3){position.x + OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[4]->colors[0]));

            DrawCubeV((Vector3){position.x , position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[4]->colors[1]));
        }
        else if(x == 1 && y == 0 && z == -1){
            DrawCubeV((Vector3){position.x + OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[7]->colors[1]));

            DrawCubeV((Vector3){position.x , position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[7]->colors[0]));
        }
        else if(x == -1 && y == 0 && z == 1){
            DrawCubeV((Vector3){position.x - OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[5]->colors[1]));

            DrawCubeV((Vector3){position.x , position.y, position.z + OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[5]->colors[0]));
        }
        else if(x == -1 && y == 0 && z == -1){
            DrawCubeV((Vector3){position.x - OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[6]->colors[0]));

            DrawCubeV((Vector3){position.x , position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE, STICKER_SIZE, 0.025f},
            get_raylib_color(cube->edgepieces[6]->colors[1]));
        }



        else if(x == 1 && y == 1 && z == 0){
            DrawCubeV((Vector3){position.x + OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[3]->colors[1]));

            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z },
            (Vector3){STICKER_SIZE, 0.025f,STICKER_SIZE},
            get_raylib_color(cube->edgepieces[3]->colors[0]));
        }
        else if(x == 1 && y == -1 && z == 0){
            DrawCubeV((Vector3){position.x + OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[9]->colors[1]));

            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[9]->colors[0]));
        }
        else if(x == -1 && y == 1 && z == 0){
            DrawCubeV((Vector3){position.x - OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[1]->colors[1]));

            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[1]->colors[0]));
        }
        else if(x == -1 && y == -1 && z == 0){
            DrawCubeV((Vector3){position.x - OFFSET , position.y , position.z},
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[11]->colors[1]));

            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z},
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(cube->edgepieces[11]->colors[0]));
        }
    }

    //centres
    else{
        if(x == 0 && y == 1 && z == 0){
            DrawCubeV((Vector3){position.x , position.y + OFFSET, position.z },
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(CUBE_WHITE));
        }
        else if(x == 0 && y == -1 && z == 0){
            DrawCubeV((Vector3){position.x , position.y - OFFSET, position.z },
            (Vector3){STICKER_SIZE, 0.025f, STICKER_SIZE},
            get_raylib_color(CUBE_YELLOW));
        }
        else if(x == 0 && y == 0 && z == 1){
            DrawCubeV((Vector3){position.x , position.y , position.z + OFFSET },
            (Vector3){STICKER_SIZE,STICKER_SIZE , 0.025f},
            get_raylib_color(CUBE_GREEN));
        }
        else if(x == 0 && y == 0 && z == -1){
            DrawCubeV((Vector3){position.x , position.y, position.z - OFFSET},
            (Vector3){STICKER_SIZE,STICKER_SIZE , 0.025f},
            get_raylib_color(CUBE_BLUE));
        }
        else if(x == 1 && y == 0 && z == 0){
            DrawCubeV((Vector3){position.x + OFFSET , position.y , position.z },
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(CUBE_RED));
        }
        else if(x == -1 && y == 0 && z == 0){
            DrawCubeV((Vector3){position.x - OFFSET, position.y, position.z },
            (Vector3){0.025f, STICKER_SIZE, STICKER_SIZE},
            get_raylib_color(CUBE_ORANGE));
        }
    }
}

void draw_cube(slot_cube* cube){
    InitWindow(1000, 800, "Rubik's Cube - 3D Visualizer");
    printf("Window initialized: %d\n", IsWindowReady());
    SetTargetFPS(60);

    // Cube rotation angles
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    float rotationZ = 0.0f;

    // Camera distance
    float distance = 10.4f;

    // Camera setup
    Camera3D camera = {0};

    camera.position = (Vector3){6.0f, 6.0f, 6.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        // Rotation speed
        float speed = 100.0f * GetFrameTime();

        // Mouse rotation
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 delta = GetMouseDelta();

            rotationY += delta.x * 0.5f;
            rotationX += delta.y * 0.5f;
        }

        // Arrow-key rotation
        if (IsKeyDown(KEY_LEFT))  rotationY -= speed;
        if (IsKeyDown(KEY_RIGHT)) rotationY += speed;
        if (IsKeyDown(KEY_UP))    rotationX -= speed;
        if (IsKeyDown(KEY_DOWN))  rotationX += speed;

        // Reset rotation
        if (IsKeyPressed(KEY_R))
        {
            rotationX = 0.0f;
            rotationY = 0.0f;
            rotationZ = 0.0f;
        }

        // Mouse-wheel zoom
        distance -= GetMouseWheelMove() * 0.8f;

        if (distance < 4.0f) distance = 4.0f;
        if (distance > 20.0f) distance = 20.0f;

        // Maintain camera direction while zooming
        camera.position = (Vector3){
            distance * 0.577f,
            distance * 0.577f,
            distance * 0.577f
        };

        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        BeginMode3D(camera);

        // Rotate the entire cube
        rlPushMatrix();

        rlRotatef(rotationX, 1.0f, 0.0f, 0.0f);
        rlRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        rlRotatef(rotationZ, 0.0f, 0.0f, 1.0f);

        // Draw all 27 cubelets
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                for (int z = -1; z <= 1; z++)
                {
                    DrawCubelet(x, y, z, cube);
                }
            }
        }

        rlPopMatrix();

        EndMode3D();

        // UI
        DrawText("Solved Rubik's Cube", 20, 20, 25, DARKGRAY);
        DrawText("Hold LEFT MOUSE + DRAG: Rotate", 20, 60, 20, DARKGRAY);
        DrawText("ARROW KEYS: Rotate", 20, 85, 20, DARKGRAY);
        DrawText("MOUSE WHEEL: Zoom", 20, 110, 20, DARKGRAY);
        DrawText("R: Reset View", 20, 135, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
}

// int main(void)
// {

//     //testing start
//     cube* canonical = (cube*)malloc(sizeof(cube));
//     cube* mutable = (cube*)malloc(sizeof(cube));

//     canonical->cornerspieces[0] = (corner){{CUBE_WHITE, CUBE_RED, CUBE_GREEN}};
//     canonical->cornerspieces[1] = (corner){{CUBE_WHITE, CUBE_GREEN, CUBE_ORANGE}};
//     canonical->cornerspieces[2] = (corner){{CUBE_WHITE, CUBE_ORANGE, CUBE_BLUE}};
//     canonical->cornerspieces[3] = (corner){{CUBE_WHITE, CUBE_BLUE, CUBE_RED}};
//     canonical->cornerspieces[4] = (corner){{CUBE_YELLOW, CUBE_ORANGE, CUBE_GREEN}};
//     canonical->cornerspieces[5] = (corner){{CUBE_YELLOW, CUBE_GREEN, CUBE_RED}};
//     canonical->cornerspieces[6] = (corner){{CUBE_YELLOW, CUBE_RED, CUBE_BLUE}};
//     canonical->cornerspieces[7] = (corner){{CUBE_YELLOW, CUBE_BLUE, CUBE_ORANGE}};

//     canonical->edgepieces[0] = (edge){{CUBE_WHITE, CUBE_GREEN}};
//     canonical->edgepieces[1] = (edge){{CUBE_WHITE, CUBE_ORANGE}};
//     canonical->edgepieces[2] = (edge){{CUBE_WHITE, CUBE_BLUE}};
//     canonical->edgepieces[3] = (edge){{CUBE_WHITE, CUBE_RED}};
//     canonical->edgepieces[4] = (edge){{CUBE_RED, CUBE_GREEN}};
//     canonical->edgepieces[5] = (edge){{CUBE_GREEN, CUBE_ORANGE}};
//     canonical->edgepieces[6] = (edge){{CUBE_ORANGE, CUBE_BLUE}};
//     canonical->edgepieces[7] = (edge){{CUBE_BLUE, CUBE_RED}};
//     canonical->edgepieces[8] = (edge){{CUBE_YELLOW, CUBE_GREEN}};
//     canonical->edgepieces[9] = (edge){{CUBE_YELLOW, CUBE_RED}};
//     canonical->edgepieces[10] = (edge){{CUBE_YELLOW, CUBE_BLUE}};
//     canonical->edgepieces[11] = (edge){{CUBE_YELLOW, CUBE_ORANGE}};

//     init_mutable(mutable,canonical);
//     slot_cube* slots = malloc(sizeof(slot_cube));
//     init_cube(slots, mutable);
//     //testing end
//     draw_cube(slots);
//     return 0;
// }
