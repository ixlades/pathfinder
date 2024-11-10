#include "libmx.h"

int return_size_of_word(const char *str, char delimiter) {
    int counter = 0;
    while (*(str + counter) != delimiter && *(str + counter) != '\0') {
        counter++;
    }
    return counter;
}

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;
    int strarr_length = mx_count_words(s, c);
    char **splited_strarr = (char**)malloc(sizeof(char*) * (strarr_length + 1));
    bool is_only_delim = true;

    for (int i = 0; i < strarr_length; i++) {
        int word_length = return_size_of_word(s,c);
        while (word_length == 0) {
            s++;
            if (*s == '\0' && is_only_delim == true) return NULL;
            word_length = return_size_of_word(s,c);
        }
        if (word_length != 0) {
            splited_strarr[i] = mx_strndup(s, word_length);
            is_only_delim = false;
        }
        if(splited_strarr[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                mx_strdel(&splited_strarr[j]);
            }
            mx_strdel(splited_strarr);
            return NULL;
        }
        s += word_length + 1;
    }
    splited_strarr[strarr_length] = NULL;
    return splited_strarr;
}

