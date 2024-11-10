#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	if(hex == NULL) {
        return 0;
    }
    for (int i = 0; hex[i] != '\0'; i++) {
        if (!(mx_isdigit(hex[i]) || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F'))) {
            return 0;
        }
    }

    unsigned long result = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        char current_char = hex[i];
        if (mx_isdigit(current_char)) {
            result = result * 16 + (current_char - '0');
        } else {
            if (mx_islower(current_char)) {
                result = result * 16 + (current_char - 'a' + 10);
            } else {
                result = result * 16 + (current_char - 'A' + 10);
            }
        }
    }

    return result;
}

