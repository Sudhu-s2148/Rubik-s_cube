#include "raylib.h"
#include "cube.h"
#include "raymath.h"
#include <stdio.h>

#define CUBELET_SIZE 0.95f
#define SPACING 1.05f
#define STICKER_SIZE 0.76f
#define STICKER_THICKNESS 0.025f
#define OFFSET 0.4905f

#define MIN_DISTANCE 3.0f
#define MAX_DISTANCE 15.0f

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
        case CUBE_NULL: return DARKGRAY;
    }
}

Vector3 get_world_position(cubelet* piece)
{
    return (Vector3)
    {
        piece->cordinate.x * SPACING,
        piece->cordinate.y * SPACING,
        piece->cordinate.z * SPACING
    };
}


void draw_sticker_cubelet(cubelet* piece){
    Vector3 sticker_dimension_x = {STICKER_THICKNESS, STICKER_SIZE, STICKER_SIZE};
    Vector3 sticker_dimension_y = {STICKER_SIZE, STICKER_THICKNESS, STICKER_SIZE};
    Vector3 sticker_dimension_z = {STICKER_SIZE, STICKER_SIZE, STICKER_THICKNESS};
    Vector3 pos = get_world_position(piece);
    DrawCubeV((Vector3){pos.x + piece->cordinate.x * OFFSET,pos.y,pos.z},sticker_dimension_x,get_raylib_color(piece->colors[0]));
    DrawCubeV((Vector3){pos.x,pos.y+piece->cordinate.y * OFFSET,pos.z},sticker_dimension_y,get_raylib_color(piece->colors[1]));
    DrawCubeV((Vector3){pos.x,pos.y,pos.z+piece->cordinate.z * OFFSET},sticker_dimension_z,get_raylib_color(piece->colors[2]));
}

void place_stickers(cube* mutable_cube){
    for(int i = 0; i<26; i++){
        draw_sticker_cubelet(&mutable_cube->pieces[i]);
    }
}

void draw_cubelet(cubelet* piece){
    Vector3 pos = get_world_position(piece);
    DrawCubeV(pos, (Vector3){CUBELET_SIZE,CUBELET_SIZE,CUBELET_SIZE},get_raylib_color(CUBE_NULL));
    draw_sticker_cubelet(piece);
}

typedef struct
{
    Vector3 target;

    float yaw;
    float pitch;
    float distance;

} OrbitCamera;


void update_orbit_camera(
    Camera3D* camera,
    OrbitCamera* orbit
)
{
    // Reset camera

    if (IsKeyPressed(KEY_R))
    {
        orbit->target = (Vector3){0, 0, 0};
        orbit->yaw = 0.75f;
        orbit->pitch = 0.55f;
        orbit->distance = 8.0f;
    }


    // Rotate camera with left mouse button

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 delta = GetMouseDelta();

        orbit->yaw -= delta.x * 0.005f;
        orbit->pitch += delta.y * 0.005f;

        // Prevent camera from flipping

        if (orbit->pitch > 1.5f)
            orbit->pitch = 1.5f;

        if (orbit->pitch < -1.5f)
            orbit->pitch = -1.5f;
    }


    // Zoom using mouse wheel

    float wheel = GetMouseWheelMove();

    orbit->distance -= wheel * orbit->distance * 0.1f;

    if (orbit->distance < MIN_DISTANCE)
        orbit->distance = MIN_DISTANCE;

    if (orbit->distance > MAX_DISTANCE)
        orbit->distance = MAX_DISTANCE;


    // Pan using middle mouse button

    if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
    {
        Vector2 delta = GetMouseDelta();

        Vector3 forward = Vector3Normalize(
            Vector3Subtract(orbit->target, camera->position)
        );

        Vector3 right = Vector3Normalize(
            Vector3CrossProduct(forward, camera->up)
        );

        Vector3 camera_up = Vector3Normalize(
            Vector3CrossProduct(right, forward)
        );

        float pan_speed = orbit->distance * 0.002f;

        Vector3 horizontal = Vector3Scale(
            right,
            -delta.x * pan_speed
        );

        Vector3 vertical = Vector3Scale(
            camera_up,
            delta.y * pan_speed
        );

        orbit->target = Vector3Add(
            orbit->target,
            Vector3Add(horizontal, vertical)
        );
    }


    // Calculate camera position using spherical coordinates

    camera->position = (Vector3)
    {
        orbit->target.x +
            orbit->distance * cosf(orbit->pitch) * sinf(orbit->yaw),

        orbit->target.y +
            orbit->distance * sinf(orbit->pitch),

        orbit->target.z +
            orbit->distance * cosf(orbit->pitch) * cosf(orbit->yaw)
    };

    camera->target = orbit->target;
}

void visualise_cube(cube* mutable_cube){
    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Rubiks Cube - Raylib");

    SetTargetFPS(60);

    // Set up 3D camera
    Camera3D camera = {0};

    camera.up = (Vector3){0, 1, 0};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;


    OrbitCamera orbit = {0};

    orbit.target = (Vector3){0, 0, 0};
    orbit.yaw = 0.75f;
    orbit.pitch = 0.55f;
    orbit.distance = 8.0f;


    // Main game loop
    while (!WindowShouldClose())
    {
        update_orbit_camera(&camera, &orbit);

        BeginDrawing();

        ClearBackground((Color){35, 35, 40, 255});

        BeginMode3D(camera);


        // Draw all cubelets
        for (int i = 0; i < 26; i++)
        {
            draw_cubelet(&mutable_cube->pieces[i]);
        }
        // printf("%.2f,%.2f,%.2f \n",mutable_cube->pieces[0].cordinate.x,mutable_cube->pieces[0].cordinate.y,mutable_cube->pieces[0].cordinate.z);


        // Draw coordinate axes
        DrawLine3D(
            (Vector3){-2, 0, 0},
            (Vector3){2, 0, 0},
            RED
        );

        DrawLine3D(
            (Vector3){0, -2, 0},
            (Vector3){0, 2, 0},
            GREEN
        );

        DrawLine3D(
            (Vector3){0, 0, -2},
            (Vector3){0, 0, 2},
            BLUE
        );

        DrawGrid(10, 1.0f);

        EndMode3D();


        DrawText(
            "RUBIK'S CUBE",
            20, 20, 25, RAYWHITE
        );

        DrawText(
            "Left Mouse: Orbit",
            20, 60, 18, LIGHTGRAY
        );

        DrawText(
            "Mouse Wheel: Zoom",
            20, 85, 18, LIGHTGRAY
        );

        DrawText(
            "Middle Mouse: Pan",
            20, 110, 18, LIGHTGRAY
        );

        DrawText(
            "R: Reset Camera",
            20, 135, 18, LIGHTGRAY
        );

        DrawFPS(20, 170);

        EndDrawing();
    }


    CloseWindow();
    return;

}

