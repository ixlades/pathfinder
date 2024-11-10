#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str == NULL) return -2;
    for (int index = 0; *(str + index) != '\0' ; index++) {
       if (*(str + index) == c) return index;
    }
    return -1;
}

