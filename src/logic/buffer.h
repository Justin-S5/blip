#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "file.h"
#include "raylib5.h"

// Initial buffer size
extern const uint32_t INIT_BUFFER_SIZE;

// Maximum buffer size of 100MB
extern const uint64_t MAX_BUFFER_SIZE;

typedef struct Item {
    size_t start;
    size_t end;
    Color color;
} Item;

#define CHAR(x) (char) x

/**
 * Used to hold the contents of a file
 */
typedef struct Buffer {
    char *items;
    size_t capacity;
    size_t length;
} Buffer;

/**
 * Create a new buffer
 * 
 * @param capacity Buffer capacity
 * 
 * @return Newly created buffer
 */
Buffer buffer_create(size_t capacity);

/**
 * Fills the buffer with the contents of the file
 * 
 * @param buffer Buffer to be filled
 * @param file File contents
 */
void buffer_fill(Buffer *buffer, FILE* file);

/**
 * Inserts a character into the buffer
 * 
 * @param buffer Buffer to be inserted into
 * @param pos Current position in the buffer
 * @param char Character to be inserted
 */
void buffer_insert(Buffer *buffer, int pos, char c);

/**
 * Clear the contents of a buffer
 * 
 * @param buffer Buffer to be cleared
 */
void buffer_clear(Buffer *buffer);

/**
 * Free a buffer in memory
 * 
 * @param buffer Buffer to be cleared
 */
void buffer_free(Buffer *buffer);

#endif // BUFFER_H
