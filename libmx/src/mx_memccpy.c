#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *chr_dst = (unsigned char *)dst;
    unsigned char *chr_src = (unsigned char *)src;

    for (size_t i = 0; i < n; ++i) {
        if (chr_src[i] == c) return &chr_src[i + 1];
        chr_dst[i] = chr_src[i];
    }
    return NULL;
}

