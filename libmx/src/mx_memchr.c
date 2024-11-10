#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *pchr_s = (unsigned char *)s;
    for (size_t i = 0; i < n; ++i) {
        if (pchr_s[i] == c) return &pchr_s[i];
    }
    return NULL;
}

