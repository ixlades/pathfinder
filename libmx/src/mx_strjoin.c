#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) return NULL;
    if (s1 == NULL) return mx_strdup(s2);
    if (s2 == NULL) return mx_strdup(s1);

    char *fin_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(fin_str, s1);
    mx_strcat(fin_str, s2);

    return fin_str;
}

