#include "libmx.h"

void *mx_memmem(void *big, size_t big_len, void *little, size_t little_len) {
    if (little_len == 0) return big;

    unsigned char *pchr_big = (unsigned char *)big;
    unsigned char *pchr_little = (unsigned char *)little;
    unsigned char *first_byte = mx_memchr(pchr_big, *pchr_little, big_len);

    while (first_byte != NULL) {
        if (!mx_memcmp(first_byte, pchr_little, little_len))
            return first_byte;
        else
            first_byte = mx_memchr(first_byte + 1, *pchr_little, mx_strlen((const char *)first_byte + 1));
    }

    return NULL;
}

