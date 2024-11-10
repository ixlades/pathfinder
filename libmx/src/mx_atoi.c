#include "libmx.h"

int mx_atoi(const char *str) {
    int result = 0;
    int sign = 1;

    // Skip leading whitespaces
    while (mx_isspace(*str)) {
        str++;
    }
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    // Convert characters to integer
    while (mx_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
