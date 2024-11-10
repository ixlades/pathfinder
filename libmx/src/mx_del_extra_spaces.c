#include "libmx.h"

int count_whitespaces(const char *str) {
    int counter = 0;

    for(int i = 1; *(str+i) != '\0'; i++) {
        if (mx_isspace(*(str + i)) && mx_isspace(*(str + i - 1))) {
            counter++;
        }
    }
    return counter;
}

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    char *trim_str = mx_strtrim(str);

    if(trim_str == NULL) return NULL;

    const int trim_len = mx_strlen(trim_str);
    if (trim_len == 0) {
     	mx_strdel(&trim_str);	
     	return mx_strnew(0);
     }
    const int clear_len = trim_len - count_whitespaces(trim_str);
    if (clear_len == 0) {
     	mx_strdel(&trim_str);	
     	return mx_strnew(0);
     }
    char *clear_str = mx_strnew(clear_len);

    if(clear_str == NULL) return NULL;
    int j = 0;
    
    for (int i = 0; i < trim_len; i++) {
        if (mx_isspace(trim_str[i])) {
            if (i > 0 && !mx_isspace(trim_str[i - 1])) {
                clear_str[j++] = ' ';
            }
        } else {
            clear_str[j++] = trim_str[i];
        }
    }
    
    mx_strdel(&trim_str);
    return clear_str;
}

