#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdint.h>

#define MODE_READ_ONLY      "r"
#define MODE_READ_WRITE     "w+"
#define MODE_READ_APPEND    "a+"

#define FILE_SIZE(f) ({             \
    size_t s = 0;                   \
    do {                            \
        fseek(f, 0, SEEK_END);      \
        s = ftell(f);               \
        fseek(f, 0, SEEK_SET);      \
    } while(0);                     \
    s;                              \
})

/**
 * Opens a new file
 * 
 * @param path File path
 * @param mode File mode
 * 
 * @return File data
 */
FILE *file_open(char *path, char *mode);

/**
 * Read bytes from a file
 * 
 * @param file File to be read
 * @param items Address where the bytes will be written to
 * @param num_items Number of items to be read
 */
void file_read(FILE *file, uint8_t *items, size_t num_items);

/**
 * Write bytes to a file
 * 
 * @param file File to be written to
 * @param items Address where the bytes will be written from
 * @param num_items Number of items to be written
 */
void file_write(FILE *file, uint8_t *items, size_t num_items);

/**
 * Closes a file
 * 
 * @param file File to close
 */
void file_close(FILE *file);

#endif // FILE_H
