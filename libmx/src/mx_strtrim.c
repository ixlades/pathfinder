#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    int start_counter = 0;
    int end_counter = 0;
    int str_length = mx_strlen(str);
	
	if (str_length == 0) return mx_strnew(0);
	
    while (mx_isspace(*(str + start_counter))) {
        start_counter++;
    }
    while (mx_isspace(*(str + str_length - end_counter - 1))) {
        end_counter++;
    }

    int new_str_len = str_length - (start_counter + end_counter);

    if (new_str_len <= 0) return mx_strnew(0);
    char *new_str = mx_strnew(new_str_len);

    if (new_str == NULL) return NULL;
    for (int i = 0; i < new_str_len ; ++i) {
        new_str[i] = str[start_counter + i];
    }

    return new_str;
}

