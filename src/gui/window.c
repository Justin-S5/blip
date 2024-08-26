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

/**
 * Get the default font
 */
#define DEFAULT_FONT GetFontDefault()

/**
 * Load a font from the given path
 */
#define LOAD_FONT(path) LoadFont(path)

#define DEFAULT_TEXT_POS ({ Vector2 default_pos = {.x = 10, .y = 10 }; default_pos; })

void window_init(void) {

    // Initialize the window
    InitWindow(WIDTH_INIT, HEIGHT_INIT, "blip");

    // Set the target FPS
    SetTargetFPS(TARGET_FPS);

    // Set configuration flags
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // No logging
    SetTraceLogLevel(LOG_NONE);

    // Open a new file
    FILE *file = file_open("main.c", MODE_READ_ONLY);

    // Create a new buffer
    Buffer buffer = buffer_create(INIT_BUFFER_SIZE);

    // Fill the buffer with the file date
    buffer_fill(&buffer, file);

    // While the window should not close
    while (!WindowShouldClose()) {

        // TODO: Add variable updates here

        // If a button is clicked, insert the element into the buffer
        uint8_t keyPressed = GetCharPressed();

        // Ignore no key presses
        if (keyPressed != 0) {

            // Get the current cursor postion


            // Insert the character into the buffer

            // DEBUG: Print the character
            printf("%c\n", CHAR(keyPressed));
        }
        // Start drawing
        BeginDrawing();

            // Set the background color
            ClearBackground(RAYWHITE);

            // Draw the file text
            DrawTextEx(LOAD_FONT("include/Consolas.ttf"), buffer.items, DEFAULT_TEXT_POS, 24, 2.0, BLACK);

            // Draw a the cursor
            DrawRectangle(80, 80, 4, 20, RED);

        // End drawings
        EndDrawing();
    }

    // Close the window
    CloseWindow();
}
