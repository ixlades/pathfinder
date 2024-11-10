#include "libmx.h" 

char *mx_strchr(const char *s, int c) {
    while (*s != c && *s != '\0') {
        ++s;
    }
    
    return (*s == c) ? (char *)s : NULL;
}

