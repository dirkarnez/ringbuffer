// #include <stdio.h> // 引入標準輸入輸出標頭檔
// #include <stddef.h> // 引入標準輸入輸出標頭檔

// void fill(char* dst, size_t dst_length, const char* src, size_t src_length) {
//     dst[0] = src[0];
// }

// int main() {
//     char buffer[5] = {0};
//     char* a = "aa";
//     fill(buffer, 5, a, 2);
    
//     printf("->%s<-", buffer); 
//     return 0; // 程式正常結束
// }
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t head;  // Write index
    size_t tail;  // Read index
    size_t count; // Current number of elements
} RingBuffer;

// Initialize the struct with an externally allocated buffer
void rb_init(RingBuffer *rb, uint8_t *buffer, size_t size) {
    rb->buffer = buffer;
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

bool rb_is_full(RingBuffer *rb) {
    return rb->count == rb->size;
}

bool rb_is_empty(RingBuffer *rb) {
    return rb->count == 0;
}

// Returns true if value was added, false if buffer was full
bool rb_push(RingBuffer *rb, uint8_t data) {
    if (rb_is_full(rb)) return false;

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % rb->size;
    rb->count++;
    return true;
}

// Returns true if value was retrieved, false if buffer was empty
bool rb_pop(RingBuffer *rb, uint8_t *out_data) {
    if (rb_is_empty(rb)) return false;

    *out_data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;
    rb->count--;
    return true;
}


#include <stdio.h>

int main() {
    // 1. Manually allocate the storage (Stack, Static, or Heap)
    uint8_t raw_storage[8];
    
    // 2. Inject the storage into the data structure
    RingBuffer rb;
    rb_init(&rb, raw_storage, sizeof(raw_storage));

    // 3. Use it
    rb_push(&rb, 42);
    rb_push(&rb, 121);

    uint8_t val;
    while (rb_pop(&rb, &val)) {
        printf("Popped: %d\n", val);
    }

    return 0;
}
