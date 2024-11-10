#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) return NULL;

    int num_of_substr = mx_count_substr(str, sub);
    int rep_diff = (mx_strlen(sub) - mx_strlen(replace)) * num_of_substr;
    char *replaced_str = mx_strnew(mx_strlen(str) - rep_diff);

    for (int i = 0; i < num_of_substr; ++i) {
        char *ptr_to_sub = mx_strstr(str, sub);
        int lenth_before_rep = ptr_to_sub - str;

        if (lenth_before_rep != 0) {
            char *str_without_changes = mx_strnew(lenth_before_rep);
            
            mx_strncpy(str_without_changes,str,lenth_before_rep);
            mx_strcat(replaced_str, str_without_changes);
            mx_strdel(&str_without_changes);
        }
        mx_strcat(replaced_str, replace);
        str += mx_strlen(sub) + lenth_before_rep;
    }
    return replaced_str;
}

