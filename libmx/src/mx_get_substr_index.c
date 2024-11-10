#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;
    const char *s = mx_strstr(str,sub);

    if (s == NULL) return -1;
    return s - str;
}

