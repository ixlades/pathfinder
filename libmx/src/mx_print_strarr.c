#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if(arr == NULL || delim == NULL) {
        exit(0);
    }

    for(int i = 0; *(arr + i) != NULL; i++) {
        mx_printstr(arr[i]);
        if (*(arr + 1 + i) != NULL) {
            mx_printchar(*delim);
        }
    }
}

