#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    if (src == NULL) return NULL;
    unsigned char *chr_dst = (unsigned char *)dst;
    unsigned char *chr_src = (unsigned char *)src;
    
    for (size_t i = 0; i < n; ++i) {
        chr_dst[i] = chr_src[i];
    }
    
    return dst;
}

