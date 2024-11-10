#include "libmx.h"
char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    char *copy_str = mx_strnew(mx_strlen(str) + 1);
    
    if (copy_str != NULL) {
        mx_strcpy(copy_str, str);
    }
    return copy_str;
}

