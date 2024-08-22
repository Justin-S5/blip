#include "file.h"

FILE *file_open(char *path, char *mode) {

    // Open the file
    FILE *file = fopen(path, mode);

    return file;
}

void file_read(FILE *file, uint8_t *items, size_t num_items) {

    // Read the specified number of bytes into the buffer
    fread(items, sizeof(*items), num_items, file);
}

void file_write(FILE *file, uint8_t *items, size_t num_items) {

    // Write the specified number of bytes from the buffer to the file
    fwrite(items, sizeof(*items), num_items, file);
}

void file_close(FILE *file) {

    // Close the file
    fclose(file);
}
