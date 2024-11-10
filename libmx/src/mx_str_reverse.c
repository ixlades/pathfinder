#include "libmx.h"

void mx_str_reverse(char *s) {
    int length = mx_strlen(s);
    
    while ((s + length - 1) > s) {
        mx_swap_char(s, (s + length - 1));
        length -= 2;
        ++s;
    }
}

