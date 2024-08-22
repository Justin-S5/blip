#include "buffer.h"

const uint32_t INIT_BUFFER_SIZE = 100000;

const uint64_t MAX_BUFFER_SIZE = 100000000000;

Buffer buffer_create(size_t capacity) {

    // If the capacity is greater than the maximum buffer size
    if (capacity > MAX_BUFFER_SIZE) {

        // Throw an error here
    }

    // Allocate memory for the buffer items
    uint8_t *items = calloc(capacity, sizeof(*items));

    // Create a new buffer
    Buffer buffer = {
        .items = items,
        .capacity = capacity,
        .length = 0
    };

    return buffer;
}

void buffer_fill(Buffer *buffer, FILE* file) {

    // Check the file size
    size_t file_size = FILE_SIZE(file);

    printf("DEBUG | File Size: %lu\n", file_size);

    // If the file size is greater than the maximum buffer size
    if (file_size > MAX_BUFFER_SIZE) {

        // Throw an error
    }

    // If the buffer size is smaller than the file size, resize the buffer
    if (buffer->capacity < file_size) {

        buffer->items = (uint8_t *) realloc(buffer->items, file_size);
    }

    // Read the contents of the file into the buffer
    fread(buffer->items, sizeof(*(buffer->items)), file_size, file);
}

void buffer_clear(Buffer *buffer) {

    // Set the buffer items to all 0s
    memset(buffer->items, 0, buffer->length);
}

void buffer_free(Buffer *buffer) {

    free(buffer->items);
}
