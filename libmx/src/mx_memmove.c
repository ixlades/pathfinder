#include "libmx.h"

void *mx_memmove(void *dst, void *src, size_t len) {
    unsigned char *pchr_dst = (unsigned char *)dst;
    unsigned char *pchr_src = (unsigned char *)src;

    if (pchr_dst < pchr_src) {
        for (size_t i = 0; i < len; i++) {
            pchr_dst[i] = pchr_src[i];
        }
    } else if (pchr_dst > pchr_src) {
        for (size_t i = len; i > 0; i--) {
            pchr_dst[i - 1] = pchr_src[i - 1];
        }
    }
    return dst;
}

