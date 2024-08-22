#include "window.h"
#include "../logic/buffer.h"

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

    // Open a new file
    FILE *file = file_open("main.c", MODE_READ_ONLY);

    // Create a new buffer
    Buffer buffer = buffer_create(INIT_BUFFER_SIZE);

    // Fill the buffer with the file date
    buffer_fill(&buffer, file);

    // While the window should not close
    while (!WindowShouldClose()) {

        // TODO: Add variable updates here

        // Start drawing
        BeginDrawing();

            // Set the background color
            ClearBackground(RAYWHITE);

            // Draw the file text
            DrawText(buffer.items, 10, 10, 20, PURPLE);

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
