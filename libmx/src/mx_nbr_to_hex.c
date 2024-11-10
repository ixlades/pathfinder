#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr < 0) {
        return 0;
    }
    unsigned long temp = nbr;
    int hex_length = 0;

    while (temp != 0){
        temp /= 16;
        hex_length++;
    }
    char *hex_string = mx_strnew(hex_length + 1);

    for (int i = hex_length - 1; i >= 0; i--) {
        int remainder = nbr % 16;
        if (remainder < 10) {
            hex_string[i] = '0' + remainder;
        } else {
            hex_string[i] = 'a' + remainder - 10;
        }
        nbr /= 16;
    }
    hex_string[hex_length] = '\0';
    
    return hex_string;
}

