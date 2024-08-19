#include "window.h"

/**
 * Initial window width
 */
#define WIDTH_INIT 800

/**
 * Initial window height
 */
#define HEIGHT_INIT 450

/**
 * Target FPS
 */
#define TARGET_FPS 60

void window_init(void) {

    // Initialize the window
    InitWindow(WIDTH_INIT, HEIGHT_INIT, "blip");

    // Set the target FPS
    SetTargetFPS(TARGET_FPS);

    // While the window should not close
    while (!WindowShouldClose()) {

        // TODO: Add updates here

        // Start drawing
        BeginDrawing();

            // Set the background color
            ClearBackground(RAYWHITE);

            // Draw text on the screen
            

        // End drawings
        EndDrawing();
    }

    // Close the window
    CloseWindow();
}

void window_close(void) {

    // Close the window
    CloseWindow();
}
