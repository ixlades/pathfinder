#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    if (str == NULL) return -1;
    int counter = 0;
    int in_word = 0;

    while (*str != '\0') {
        if (*str != delimiter && in_word == 0) {
            in_word = 1;
            counter++;
        } else if (*str == delimiter) in_word = 0;
        str++;
    }
    return counter;
}

