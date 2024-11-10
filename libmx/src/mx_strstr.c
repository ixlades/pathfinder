#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len = mx_strlen(needle);
    if (len == 0) return (char *)haystack;
    char *first_chr = mx_strchr(haystack, *needle);

    while (first_chr != NULL) {
       if (!mx_strncmp(first_chr, needle, len)) {
           return (char *)first_chr;
       } else {
           first_chr = mx_strchr(first_chr + 1, *needle);
       }
    }
    return NULL;
}

