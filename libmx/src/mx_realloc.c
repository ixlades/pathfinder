#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) return malloc(size);
    if (ptr != NULL && size == 0) {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(size);
    
    mx_memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

